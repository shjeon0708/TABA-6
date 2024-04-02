sudo rm -f /etc/yum.repos.d/mysql*

sudo dnf install https://dev.mysql.com/get/mysql80-community-release-el9-1.noarch.rpm

sudo rpm --import https://repo.mysql.com/RPM-GPG-KEY-mysql-2022

sudo yum update

sudo dnf install mysql-community-server

sudo systemctl start mysqld.service

sudo systemctl status mysqld.service
