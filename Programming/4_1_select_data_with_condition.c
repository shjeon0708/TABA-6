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

    // 특정 전공의 학생 데이터 조회
    const char *select_query = "SELECT id, name, age, student_id, email, major, year FROM students WHERE major = 'Computer Science'";
    if (mysql_query(conn, select_query)) {
        fprintf(stderr, "SELECT failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        fprintf(stderr, "mysql_store_result() failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    printf("ID | Name   | Age | Student_ID | Email              | Major            | Year\n");
    printf("---------------------------------------------------------------------\n");
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    mysql_free_result(result);

    // 연결 종료
    mysql_close(conn);
    return 0;
}
