CSAPP c7
===

c 预处理器: cpp

静态链接
![图 2](https://i.loli.net/2021/10/07/IxLtM5pyCfGWg64.png)  

.c (cpp)-> .i(ascii) (cc1 编译器)-> .S(ascii) (as 汇编器)-> .o(可重定位目标文件) (ld 链接器)-> .(可执行目标文件)

![图 3](https://i.loli.net/2021/10/07/GuI6Scn9h4vDgzo.png)  

#### 目标文件

Unix: a.out
Windows: PE(可移植可执行)
Mac-OS-X: Mach-O
x86-64 Linux: ELF(可执行可链接格式)

#### 可重定位目标文件

![图 4](https://i.loli.net/2021/10/07/G8TONSM34wLJexb.png)  

不同节的位置和大小是由头部节点决定的

#### 符号和符号表

![图 5](https://i.loli.net/2021/10/07/rsDhA7uCNPF8TnQ.png)  

每个符号都被分配到目标文件的某个节

伪节(pseudo-section):
- ABS 不该被重定位的符号
- UNDEF 未定义的符号
- COMMON 还未被分配位置的未初始化符号

![图 6](https://i.loli.net/2021/10/07/NLzrxoe1GZEMFmi.png)  


static 在 C 中，内部的变量是不在栈上管理的，而是在 .data 和 .bss 段为每个定义分配空间，在符号表中有唯一的名字

