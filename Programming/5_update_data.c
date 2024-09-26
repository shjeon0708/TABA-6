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

    // 데이터 업데이트
    const char *update_query = "UPDATE students SET year = 5 WHERE name = 'David'";
    if (mysql_query(conn, update_query)) {
        fprintf(stderr, "UPDATE failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }
    printf("Data updated successfully.\n");

    // 연결 종료
    mysql_close(conn);
    return 0;
}
