C언어 개발 환경 설치

sudo yum install mysql-devel gcc g++

wget https://dev.mysql.com/get/Downloads/Connector-C++/mysql-connector-c++-jdbc-9.0.0-1.el9.x86_64.rpm

sudo yum install -y mysql-connector-c++-jdbc-9.0.0-1.el9.x86_64.rpm


컴파일
gcc -o check_connection 1_check_connection.c -lmysqlclient -I/usr/include/mysql -L/usr/lib64/mysql
gcc -o create_table 2_create_table.c -lmysqlclient -I/usr/include/mysql -L/usr/lib64/mysql
gcc -o insert_data 3_insert_data.c -lmysqlclient -I/usr/include/mysql -L/usr/lib64/mysql
gcc -o select_data 4_select_data_1.c -lmysqlclient -I/usr/include/mysql -L/usr/lib64/mysql
gcc -o select_data 4_select_data_2.c -lmysqlclient -I/usr/include/mysql -L/usr/lib64/mysql
gcc -o update_data 5_update_data.c -lmysqlclient -I/usr/include/mysql -L/usr/lib64/mysql
gcc -o delete_data 6_delete_data.c -lmysqlclient -I/usr/include/mysql -L/usr/lib64/mysql
