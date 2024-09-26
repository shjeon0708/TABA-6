#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    MYSQL *conn;

    // MySQL 초기화
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return 1;
    }

    // MySQL 서버에 연결 [계정 : root / 패스워드 : your_password / DB : testdb]
    if (mysql_real_connect(conn, "localhost", "root", "your_password", "testdb", 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    // 연결 성공 확인
    printf("Connection successful!\n");

    // 연결 종료
    mysql_close(conn);
    return 0;
}
