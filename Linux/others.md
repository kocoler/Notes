#### IOWait

%wa，软中断是 %si

就是接收和处理 硬件中端 占 CPU 的时间

这意味着 CPU 没有干别的事情，就是在等他 IO 完成

#### mainframe os

大型机上的操作系统
我觉得比较典型的就是 z/os
linux 在上面跑可以跑在 z/vm 上

https://www.ibm.com/docs/en/zos-basic-skills?topic=today-what-are-mainframe-operating-systems

#### IPL

IPL (initial program load) is a mainframe term for the loading of the operating system into the computer's main memory . A mainframe operating system (such as OS/390) contains many megabytes of code that is customized by each installation, requiring some time to load the code into the memory.

总的来说就是这个名词是适用于 mainframe 大型机上的，典型的有

#### ASLR

ASLR (Address space layout randomization)

主要是防止 overflow attack
可以通过 gcc 来控制，也可以在系统的 IPL 的时候控制(对于大型机来说)
linux 的配置里有写，linux 还是牛的呀
当然 windows 也有

https://www.networkworld.com/article/3331199/what-does-aslr-do-for-linux.html
ref: https://www.ibm.com/docs/en/zos/2.4.0?topic=overview-address-space-layout-randomization
