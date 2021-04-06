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

  

- 进程

  按照进程的功能和运行的程序分类，进程可划分为两大类：

  (1) 系统进程：可以执行内存资源分配和进程切换等管理工作；而且，该进程的运行不受用户的干预，即使是root用户也不能干预系统进程的运行。

  (2) 用户进程：通过执行用户程序、应用程序或内核之外的系统程序而产生的进程，此类进程可以在用户的控制下运行或关闭。

  针对用户进程，又可以分为交互进程、批处理进程和守护进程三类。
  (1) 交互进程：由一个shell终端启动的进程，在执行过程中，需要与用户进行交互操作，可以运行于前台，也可以运行在后台。

  (2) 批处理进程：该进程是一个进程集合，负责按顺序启动其他的进程。  

  (3) 守护进程：守护进程是一直运行的一种进程，经常在linux系统启动时启动，在系统关闭时终止。它们独立于控制终端并且周期性的执行某种任务或等待处理某些发生的事件。例如httpd进程，一直处于运行状态，等待用户的访问。还有经常用的crond进程，这个进程类似与windows的计划任务，可以周期性的执行用户设定的某些任务。

  

- 交换分区

  目前Red Hat（红帽官方）推荐交换分区的大小应当与系统物理内存的大小保持线性比例关系。
  在小于2GB物理内存的系统中，交换分区大小应该设置为内存大小的**两倍**（1.5-2）；
  如果内存大小多于2GB，交换分区大小应该是物理内存大小加上2GB；
  原则上，由于交换分区读写速度比真正内存区慢的多，因此在实际应用中如果不是特别需要应该设置的越小越好。

  

- glibc

  glibc是GNU发布的libc库，即c运行库。glibc是linux系统中最底层的api，几乎其它任何运行库都会依赖于glibc。

  glibc 和 libc 都是 Linux 下的 C 函数库。

  libc 是 Linux 下的 ANSI C 函数库；glibc 是 Linux 下的 GUN C 函数库。



- Shebang (Unix)

  ```shell
  #!interpreter [optional-arg]
  ```

  ```shell
  #!/usr/bin/env sh
  ```


