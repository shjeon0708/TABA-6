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

    // 데이터 삭제
    const char *delete_query = "DELETE FROM students WHERE name = 'Charlie'";
    if (mysql_query(conn, delete_query)) {
        fprintf(stderr, "DELETE failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }
    printf("Data deleted successfully.\n");

    // 연결 종료
    mysql_close(conn);
    return 0;
}
