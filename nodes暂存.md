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




Other
===

再遇到正则的性能问题时，正则表达式的优化手段主要有3个：

1. 我们需要尽可能的去让我们的正则表达式准确化，越准确的正则表达式匹配时，他的回溯情况就越少，所以它的性能就越高。
2. 在正则表达式已经没有办法再进行优化的情况下，我们可以先选取一些没有回复情况的特征值进行先置条件判断，这样的话，我们能够尽量多的去避免一些无意义的好事匹配，优化我们的性能。
3. 借助其他线程或者服务来进行正则处理，避免用户卡顿。



浏览器内核一般包含两个引擎：页面排版引擎 和 JS引擎
IE的 使用的自己的Trident 内核
FireFox 是Gecko内核
Opera 是Presto内核
Safari 使用的Webkit 内核
Chrome 是Google自己的 javascript V8引擎 而其页面排版采用的Webkit 内核



1072693248=1 =》定义一个有符号的double变量，赋值1.0，再取高32位，就是这个数。



国标码在windows上的什么编码是936 cmd默认936，可以用chcp查询，然后chcp 65001可以切换到 utf-8，然后就不会乱码了



左值：左值可以表示对象，即具有对应的可以由用户访问的存储单元（C的左值相当于Java中的“变量”）。正因为如此，用于取得对象的指针的内建操作符&要求操作数是左值。左值是存储单元（地址，容器），右值是值（内容）。



- paste 

  ```bash
  $ paste [-s][-d <间隔字符>][--help][--version][文件...]
  ```
  将文件按列合并
  
  行合并？-> cat
  
- bc

  任意精度计算器语言

  ```bash
  $ echo "5+6" | bc
  $ 11
  
  scale=2; // 两位小数
  echo "ibase=2; obase=2; 1+1" | bc
  
  ...
  ```

- at

  定时执行任务

  ```bash
  $ at 5pm+3 days // 三天后的下午 5 点锺
  $ >at ....
  $ >at <EOT>
  
  $ atq // 查看所有已设置的任务
  
  $ at -c 8 // 查看任务8
  ```

  > https://ipcmen.com/at

- zcat

  mac下：gunzip -c xxx

  不解压只输出的gzip格式包

  zip格式的？  unzip -l xxx

  zipinfo

  ```bash
  $ unzip -l zipT.zip
  Archive:  zipT.zip
    Length      Date    Time    Name
  ---------  ---------- -----   ----
       2864  12-05-2020 16:28   loginccnuwifi.go
  ---------                     -------
       2864                     1 file
  
  $ gunzip -c tarT.tar.gz
  loginccnuwifi.go000644 000765 000024 00000005460 13762642273 014171 0ustar00macstaff000000 000000 package main
  
  import (
  	"flag"
  	"fmt"
  	"io/ioutil"
  	"net/http"
  	"n
  	...
  	
  $ gunzip -l tarT.tar.gz
    compressed uncompressed  ratio uncompressed_name
          1349         4608  70.7% tarT.tar
          
  $ zipinfo zipT.zip
  Archive:  zipT.zip
  Zip file size: 1417 bytes, number of entries: 1
  -rw-r--r--  3.0 unx     2864 tx defN 20-Dec-05 16:28 loginccnuwifi.go
  1 file, 2864 bytes uncompressed, 1235 bytes compressed:  56.9%
  ```

- rsync

  它可以在本地计算机与远程计算机之间，或者两个本地目录之间同步文件（但不支持两台远程计算机之间的同步）。它也可以当作文件复制工具，替代`cp`和`mv`命令。

  ```bash
  $ rsync -av source/ destination // 递归复制 仅复制变化文件
  
  $ rsync -av --exclude='*.txt' --exclude-from='exclude-file.txt' --exclude={'file1.txt','dir1/*'}source/ destination // 排除文件
  
  $ rsync -av --include="*.txt" --exclude='*' source/ destination // 排除所有只包含 .txt 格式文件
  
  $ rsync -anv source/ destination // 模拟
  
  $ rsync -av --delete source/ destination // 制作镜像备份 删除只存在于目标目录、不存在于源目录的文件。
  
  $ rsync -av -e 'ssh -p 2234' source/ user@remote_host:/destination // -e ssh参数
  ```

  > http://www.ruanyifeng.com/blog/2020/08/rsync.html

- cal

  日历

  ```bash
  $ cal
        十二月 2020
  日 一 二 三 四 五 六
         1  2  3  4  5
   6  7  8  9 10 11 12
  13 14 15 16 17 18 19
  20 21 22 23 24 25 26
  27 28 29 30 31
  
  $ cal -d 2020-12 // 指定年-月
  
  $ cal 2020
  
  $ cal -j
           十二月 2020
   日  一  二  三  四  五  六
          336 337 338 339 340
  341 342 343 344 345 346 347
  348 349 350 351 352 353 354
  355 356 357 358 359 360 361
  362 363 364 365 366
  
  $ ncal
      十二月 2020
  一      7 14 21 28
  二   1  8 15 22 29
  三   2  9 16 23 30
  四   3 10 17 24 31
  五   4 11 18 25
  六   5 12 19 26
  日   6 13 20 27
  
  
  $ calendar // 节日
  
  ```

  > https://linux.cn/article-9576-1.html

- date

  日期

  ```bash
  $ date
  2020年12月 9日 星期三 22时31分18秒 CST
  ```

- diff

  ```bash
  $ diff [file1] [file2]
  
  $ diff -r [dir]
  ```

  

  



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

