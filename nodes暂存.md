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

  

- 
