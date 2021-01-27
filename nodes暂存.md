MySQL
===

关于or条件的优化

> https://blog.csdn.net/fsp88927/article/details/80662422
>
> MySQL在 5.0版本中引入新特性：索引合并优化(Index merge optimization)，当查询中单张表可以使用多个索引时，同时扫描多个索引并将扫描结果进行合并。

该特新主要应用于以下三种场景：

-  对OR语句求并集，如查询SELECT * FROM TB1 WHERE c1="xxx" OR c2=""xxx"时，如果c1和c2列上分别有索引，可以按照c1和c2条件进行查询，再将查询结果合并（union）操作，得到最终结果
-  对AND语句求交集，如查询SELECT * FROM TB1 WHERE c1="xxx" AND c2=""xxx"时，如果c1和c2列上分别有索引，可以按照c1和c2条件进行查询，再将查询结果取交集（intersect）操作，得到最终结果
- 对AND和OR组合语句求结果

```mysql
SELECT *
FROM tb_xxxx_xxxx
WHERE yn=0
AND C1=‘123456789’
OR C2=‘123456789’;
```

====>

```mysql
SELECT *
FROM tb_xxxx_xxxx
WHERE yn=0
AND C1=‘123456789’
UNION ALL
SELECT *
FROM tb_xxxx_xxxx
WHERE yn=0
AND C2=‘123456789’
AND C1<>‘123456789’
```



#### DML、DDL、DCL区别



#### OLTP与OLAP

OLTP（on-line transaction processing）翻译为联机事务处理， OLAP（On-Line Analytical Processing）翻译为联机分析处理，从字面上来看OLTP是做事务处理，OLAP是做分析处理。从对数据库操作来看，OLTP主要是对数据的增删改，OLAP是对数据的查询。

<img src="/Users/mac/Documents/Notes/nodes暂存.assets/image-20210119101757350.png" alt="image-20210119101757350" style="zoom: 33%;" />

从可扩展性上看：Kylin=Impala/Spark>MPP数据库>传统数据库；从对硬件要求上看，传统数据库>MPP数据库>Impala/Spark>=Kylin；从响应效率上来看，不同的数据量、并发数，响应效率差别不一，但可以确定的是，要计算的数据量越大，并发的用户数越多，同等资源情况下预计算的响应效率会越发明显。






Other
===

- **tips**

  正则：

  再遇到正则的性能问题时，正则表达式的优化手段主要有3个：

  1. 我们需要尽可能的去让我们的正则表达式准确化，越准确的正则表达式匹配时，他的回溯情况就越少，所以它的性能就越高。
  2. 在正则表达式已经没有办法再进行优化的情况下，我们可以先选取一些没有回复情况的特征值进行先置条件判断，这样的话，我们能够尽量多的去避免一些无意义的好事匹配，优化我们的性能。
  3. 借助其他线程或者服务来进行正则处理，避免用户卡顿。



- **浏览器**

  浏览器内核一般包含两个引擎：页面排版引擎 和 JS引擎
  IE的 使用的自己的Trident 内核
  FireFox 是Gecko内核
  Opera 是Presto内核
  Safari 使用的Webkit 内核
  Chrome 是Google自己的 javascript V8引擎 而其页面排版采用的Webkit 内核



- **位运算	**

  1072693248=1 =》定义一个有符号的double变量，赋值1.0，再取高32位，就是这个数。



- **编码**

  国标码在windows上的什么编码是936 cmd默认936，可以用chcp查询，然后chcp 65001可以切换到 utf-8，然后就不会乱码了



- **C**

  左值：左值可以表示对象，即具有对应的可以由用户访问的存储单元（C的左值相当于Java中的“变量”）。正因为如此，用于取得对象的指针的内建操作符&要求操作数是左值。左值是存储单元（地址，容器），右值是值（内容）。

  


Linux
===

- argc argv optind opterr optopt optarg

  参数argc和argv：

     通常是从main的参数直接传递而来，argc是参数的数量，argv是一个常量字符串数组的地址。
  参数optstring：

     一个包含正确选项字符的字符串，如果一个字符后面有冒号，那么这个选项在传递参数时就需要跟着一个参数。
  外部变量：

  char *optarg：如果有参数，则包含当前选项参数字符串
  int optind：**argv的当前索引值。当getopt函数在while循环中使用时，剩下的字符串为操作数，下标从optind到argc-1**。
  int opterr：这个变量非零时，getopt()函数为“无效选项”和“缺少参数选项，并输出其错误信息。
  int optopt：当发现无效选项字符之时，getopt()函数或返回 \’ ? \’ 字符，或返回字符 \’ : \’ ，并且optopt包含了所发现的无效选项字符。

  > https://www.cnblogs.com/xhg940420/p/7016574.html



- POSIX

  **可移植操作系统接口**（Portable Operating System Interface，缩写为**POSIX**）是 IEEE 为要在各种 UNIX 操作系统 上运行软件，而定义 API 的一系列互相关联的标准的总称，

  当前的POSIX主要分为四个部分：Base Definitions、System Interfaces、Shell and Utilities和Rationale。

  **unistd.h** 是 C 和 C++ 程序设计语言中提供对 POSIX 操作系统 API 的访问功能的头文件的名称。该头文件由 POSIX.1 标准（可移植系统接口）提出，故所有遵循该标准的操作系统和编译器均应提供该头文件。

  对于类 Unix 系统，unistd.h 中所定义的接口通常都是大量针对系统调用的封装（英语：wrapper functions），如 fork、pipe 以及各种 I/O 原语（read、write、close 等等）。

  > https://cloud.tencent.com/developer/ask/26856



- 命令行<, [, ...区别

  在方括号内的表达式(“[” 和 “]”之间的字符)是**可选**的（写命令时要去掉括号）。
  在尖括号内的表达式(“<” 和 “>”之间的字符)是**必须替换**的表达式(而且要去掉括号)。

  省略号表示该选项可以单个或多个



- Unit

  Systemd 可以管理所有系统资源。不同的资源统称为 Unit（单位）。

  



MAC
===



- **应用文件位置**：

  - **Configuration**

    ```
    ~/Library/Preferences/
    ```

  - **Caches**

    ```
    ~/Library/Caches/
    ```

  - **Plugins**

    ```
    ~/Library/Application Support/
    ```

  - **Logs**

    ```
    ~/Library/Logs/
    ```

