MySQL
===

<img src="/Users/mac/Library/Application Support/typora-user-images/image-20210118203312630.png" alt="image-20210118203312630" style="zoom:50%;" />

配置文件里定义了许多个组，组名分别是`server`、`mysqld`、`mysqld_safe`、`client`、`mysql`、`mysqladmin`。每个组下边可以定义若干个启动选项，

- 字符集

<img src="/Users/mac/Library/Application Support/typora-user-images/image-20210120215245224.png" alt="image-20210120215245224" style="zoom:50%;" />

​		

  ```mysql
mysql> SHOW VARIABLES LIKE 'character_set_server'; # 服务器级别默认的字符集

mysql> SHOW VARIABLES LIKE 'collation_server'; # 默认的比较规则
  ```

