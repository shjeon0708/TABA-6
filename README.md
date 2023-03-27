TABA 2 




**Java설치**
yum list java*jdk-devel

yum update

yum install -y java-18-openjdk-devel.x86_64

which javac

ls -l /usr/bin/javac

readlink /etc/alternatives/javac

 vi ~/.bash_profile

export JAVA_HOME=/usr/lib/jvm/java-1.8.0-openjdk-1.8.0.362.b09-4.el9.x86_64
export PATH=$PATH:$JAVA_HOME/bin

source ~/.bash_profile
