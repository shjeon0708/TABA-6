import requests
import MySQLdb

# API URL과 API 키, 본인의 api_key 입력
url = 'https://api.odcloud.kr/api/3080606/v1/uddi:0168ee9b-b6a6-49e1-a299-86bfcf3a1860_201705301403'
api_key = ' ' 

# API 요청
params = {
    'page': 1,
    'perPage': 900,
    'serviceKey': api_key
}
response = requests.get(url, params=params)

# 응답 데이터 확인
if response.status_code == 200:
    data = response.json()['data']
else:
    print(f"API 요청 실패: {response.status_code}")
    exit()

# MySQL 연결
db = MySQLdb.connect(
    host="localhost",
    user="root",
    passwd="password",
    db="corporation",
    charset='utf8'
)
cursor = db.cursor()

# 데이터 삽입
try:
    for item in data:
        sql = """
        INSERT INTO corporation_data (법인구분, 법인성격, 법인종류, 법인주소, 설립일자, 연번, 현재법인명)
        VALUES (%s, %s, %s, %s, %s, %s, %s)
        """
        cursor.execute(sql, (
            item['법인구분'], 
            item['법인성격'], 
            item['법인종류'], 
            item['법인주소'], 
            item['설립일자'], 
            item['연번'], 
            item['현재법인명']
        ))

    # 커밋
    db.commit()

except MySQLdb.Error as e:
    print(f"Error: {e}")
    db.rollback()

finally:
    cursor.close()
    db.close()
