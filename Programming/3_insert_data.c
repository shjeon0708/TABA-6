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

    // 데이터 삽입 (30개)
    const char *insert_query = "INSERT INTO students (name, age, student_id, email, major, year) VALUES "
                               "('Alice', 23, 'S12345', 'alice@example.com', 'Computer Science', 3), "
                               "('Bob', 25, 'S12346', 'bob@example.com', 'Mathematics', 2), "
                               "('Charlie', 22, 'S12347', 'charlie@example.com', 'Physics', 1), "
                               "('David', 24, 'S12348', 'david@example.com', 'Engineering', 4), "
                               "('Eva', 21, 'S12349', 'eva@example.com', 'Biology', 3), "
                               "('Frank', 26, 'S12350', 'frank@example.com', 'Literature', 2), "
                               "('Grace', 20, 'S12351', 'grace@example.com', 'Mathematics', 1), "
                               "('Hank', 22, 'S12352', 'hank@example.com', 'Physics', 4), "
                               "('Ivy', 23, 'S12353', 'ivy@example.com', 'Computer Science', 2), "
                               "('Jack', 24, 'S12354', 'jack@example.com', 'Engineering', 3), "
                               "('Kathy', 21, 'S12355', 'kathy@example.com', 'Biology', 2), "
                               "('Leo', 22, 'S12356', 'leo@example.com', 'Mathematics', 1), "
                               "('Mia', 23, 'S12357', 'mia@example.com', 'Physics', 4), "
                               "('Nina', 20, 'S12358', 'nina@example.com', 'Computer Science', 3), "
                               "('Oscar', 26, 'S12359', 'oscar@example.com', 'Literature', 2), "
                               "('Paul', 21, 'S12360', 'paul@example.com', 'Mathematics', 1), "
                               "('Quinn', 22, 'S12361', 'quinn@example.com', 'Physics', 4), "
                               "('Rachel', 23, 'S12362', 'rachel@example.com', 'Computer Science', 2), "
                               "('Sam', 24, 'S12363', 'sam@example.com', 'Engineering', 3), "
                               "('Tina', 21, 'S12364', 'tina@example.com', 'Biology', 2), "
                               "('Uma', 22, 'S12365', 'uma@example.com', 'Mathematics', 1), "
                               "('Victor', 23, 'S12366', 'victor@example.com', 'Physics', 4), "
                               "('Wendy', 20, 'S12367', 'wendy@example.com', 'Computer Science', 3), "
                               "('Xander', 26, 'S12368', 'xander@example.com', 'Literature', 2), "
                               "('Yara', 21, 'S12369', 'yara@example.com', 'Mathematics', 1), "
                               "('Zoe', 22, 'S12370', 'zoe@example.com', 'Physics', 4), "
                               "('Aiden', 23, 'S12371', 'aiden@example.com', 'Computer Science', 2), "
                               "('Blake', 24, 'S12372', 'blake@example.com', 'Engineering', 3), "
                               "('Chloe', 21, 'S12373', 'chloe@example.com', 'Biology', 2), "
                               "('Dylan', 22, 'S12374', 'dylan@example.com', 'Mathematics', 1), "
                               "('Elena', 23, 'S12375', 'elena@example.com', 'Physics', 4), "
                               "('Felix', 20, 'S12376', 'felix@example.com', 'Computer Science', 3), "
                               "('Gina', 26, 'S12377', 'gina@example.com', 'Literature', 2), "
                               "('Henry', 21, 'S12378', 'henry@example.com', 'Mathematics', 1), "
                               "('Irene', 22, 'S12379', 'irene@example.com', 'Physics', 4)";

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
