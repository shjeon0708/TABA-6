#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    MYSQL *conn;

    // MySQL 초기화 및 연결
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return 1;
    }

    if (mysql_real_connect(conn, "localhost", "root", "your_password", "testdb", 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    // 테이블 생성
    const char *create_table_query = "CREATE TABLE IF NOT EXISTS students ("
                                     "id INT PRIMARY KEY AUTO_INCREMENT, "
                                     "name VARCHAR(255), "
                                     "age INT, "
                                     "student_id VARCHAR(10), "
                                     "email VARCHAR(255), "
                                     "major VARCHAR(255), "
                                     "year INT)";
    if (mysql_query(conn, create_table_query)) {
        fprintf(stderr, "CREATE TABLE failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }
    printf("Table created successfully.\n");

    // 연결 종료
    mysql_close(conn);
    return 0;
}
