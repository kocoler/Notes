Core dump
===

Core:
> 在使用半导体作为内存的材料前，人类是利用线圈当作内存的材料（发明者为王安），线圈就叫作 core ，用线圈做的内存就叫作 core memory。如今 ，半导体工业澎勃发展，已经没有人用 core memory 了，不过，在许多情况下， 人们还是把记忆体叫作 core 。

就是 crash(本身或者发信号) 之后的 debug 文件啦

> Linux平台常用的coredump文件分析工具是gdb；Solaris平台用pstack和pflags；Windows平台用userdump和windbg。

生成的文件就在当前目录，一般。

作用方式: **trigger** 或者是 helper program(?)

用法:
记得设置 ulimit -c unlimited
> $ gdb executable_file core_file

ref:
> https://wiki.archlinux.org/title/Core_dump
> http://blog.chinaunix.net/uid-20653148-id-1591419.html
