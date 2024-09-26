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

    // 데이터 삽입
    const char *insert_query = "INSERT INTO students (name, age, student_id, email, major, year) VALUES "
                               "('Alice', 23, 'S12345', 'alice@example.com', 'Computer Science', 3), "
                               "('Bob', 25, 'S12346', 'bob@example.com', 'Mathematics', 2), "
                               "('Charlie', 22, 'S12347', 'charlie@example.com', 'Physics', 1), "
                               "('David', 24, 'S12348', 'david@example.com', 'Engineering', 4)";
    if (mysql_query(conn, insert_query)) {
        fprintf(stderr, "INSERT failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }
    printf("Data inserted successfully.\n");

    // 연결 종료
    mysql_close(conn);
    return 0;
}
