Linux 命令行
===

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
  
  $ rsync -av --exclude="*.txt" --include='*' source/ destination // 排除所有只包含 .txt 格式文件
  
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

- systemctl

  ```bash
  $ systemctl list-dependencies --all nginx.service // 查看所有依赖项
  $ systemctl list-unit-files --type=service // 所有的 systemctl type 可指定
  $ systemctl status gdm.service // 某个服务状态
  $ sudo systemctl daemon-reload // 重载所有修改过的配置文件
  $ systemctl show httpd.service // 重载所有修改过的配置文件
  $ systemctl show -p CPUShares httpd.service // 显示某个 Unit 的指定属性的值
  $ sudo systemctl set-property httpd.service CPUShares=500 // 设置某个 Unit 的指定属性
  $ systemctl cat atd.service // 查看配置文件的内容
  ```

  > https://www.freedesktop.org/software/systemd/man/systemd.unit.html

- journalctl

  ```bash
  $ sudo journalctl -f -u nginx.service // 查看 xxx 的日志
  ```

- whatis

  ```bash
  $ whatis man // 显示命令行简介
  ```

- scr (System Activity Reporter系统活动情况报告)

  ```bash
  $ sar -u 1 10 // cpu 利用率 （1：每隔一秒，10：写入10次）
  $ sar -r 1 10 // 内存 利用率
  $ sar -d 1 10 // 磁盘 io
  $ sar -n DEV 1 2 // 网路流量
  ```

  > https://www.cnblogs.com/zcx-python/p/9001630.html
  
- shred（文件粉碎）

  ```bash
  $ shred xx.xx // 覆盖
  $ shred -u xx.xx // remove
  ```

- hash

  命令运行时系统优先查询的哈希表

  ```bash
  $ hash
  ...
  go=/usr/local/go/bin/go
  gopkgs=/usr/local/go/bin/gopkgs
  ...
  ```

- unexpand（转换空格和TAB）

  ```bash
  $ unexpand -a -t 4 xxx.txt
  ```

- trancerouter

  hop by hop 的发送 ping

  icmp 协议

  ```bash
  $ trancerouter www.example.com
  ```

- stat

  查看inode信息

  ```bash
  root@xxx:~# stat Documents/Dockerfile
    File: Documents/Dockerfile
    Size: 254       	Blocks: 8          IO Block: 4096   regular file
  Device: fc01h/64513d	Inode: 1061040     Links: 1
  Access: (0644/-rw-r--r--)  Uid: (    0/    root)   Gid: (    0/    root)
  Access: 2021-01-25 21:26:07.054177462 +0800
  Modify: 2020-12-05 20:18:21.897935577 +0800
  Change: 2020-12-05 20:18:21.897935577 +0800
   Birth: -
   
  ```

- tee

  ```bash
  $ echo "something" | tee -a file
  ```

- w 登陆信息

  ```shell
  $ w
   0:14  up 30 days, 15:04, 6 users, load averages: 1.73 1.84 2.19
  USER     TTY      FROM              LOGIN@  IDLE WHAT
  mac      console  -                07 321  30days -
  mac      s005     -                二18       5 -zsh
  mac      s004     -                 0:07       - w
  mac      s002     -                一22    5:51 -zsh
  mac      s003     -                二18    3:08 -zsh
  mac      s001     -                21 321  26:47 /usr/bin/less
  ```

- netstat 网络信息

  ```shell
  $ netstat -atu
  ```

- ss

  ```shell
  $ ss -tln
  ```

- ps

  > PROCESS STATE CODES
  >       Here are the different values that the s, stat and state output specifiers (header "STAT" or "S") will display to describe the state of a process:
  >       D    uninterruptible sleep (usually IO)
  >       R    running or runnable (on run queue)
  >       S    interruptible sleep (waiting for an event to complete)
  >       T    stopped, either by a job control signal or because it is being traced.
  >       W    paging (not valid since the 2.6.xx kernel)
  >       X    dead (should never be seen)
  >       Z    defunct ("zombie") process, terminated but not reaped by its parent.
  >
  >       For BSD formats and when the stat keyword is used, additional characters may be displayed:
  >       <    high-priority (not nice to other users)
  >       N    low-priority (nice to other users)
  >       L    has pages locked into memory (for real-time and custom IO)
  >       s    is a session leader
  >       l    is multi-threaded (using CLONE_THREAD, like NPTL pthreads do)
  >          +    is in the foreground process group.

  查看线程运行在哪个 CPU 上

  ```shell
  $ ps a -o pid,psr,command ...
  ```

  其他方法

- namp

  端口开放扫描

  -p 指定端口

  ```bash
  $ nmap 127.0.0.1
  Starting Nmap 7.91 ( https://nmap.org ) at 2021-05-19 13:29 CST
  Nmap scan report for localhost (127.0.0.1)
  Host is up (0.00048s latency).
  Not shown: 995 closed ports
  PORT     STATE SERVICE
  1080/tcp open  socks
  1087/tcp open  cplscrambler-in
  3000/tcp open  ppp
  3306/tcp open  mysql
  9000/tcp open  cslistener
  
  Nmap done: 1 IP address (1 host up) scanned in 7.01 seconds
  ```

- mtr

  enhance trancerouter

- jq

  json处理器

  ```bash
  $ jq -c . input.json // compose json to one line
  $ jq . // beautify json
  ```

- iperf
  internet perform
  ```bash
  $ iperf -c 127.0.0.1 -e -i 1 # c
  $ iperf -s ... # s
  ```

与 linux 内核/驱动有关的
- lspci
  
  可以查看当前系统中所有PCI的设备的信息

- lsmod
  
  列出当前系统中所有已经加载了的模块/驱动

- modinfo
  
  命令可以单看指定的模块/驱动的信息

- **readelf**
  
  解析 elf 信息
  ```bash
  $ readelf -a a.out
  ```

- size
  
  程序内存映像大小
  ```bash
  $ size a.out
   text	   data	    bss	    dec	    hex	filename
   1095	    532	      4	   1631	    65f	a.out
  ```

- nm
  
  查看 obj 的符号
  ```bash
  $ nm a.out
  0000000000601024 B __bss_start
  0000000000601024 b completed.6355
  0000000000601020 D __data_start
  0000000000601020 W data_start
  0000000000400410 t deregister_tm_clones
  ...
  
  00000000004004cd T main
  0000000000400440 t register_tm_clones
  00000000004003e0 T _start
  0000000000601028 D __TMC_END__
  ```

- ldd
  
  查看程序依赖库
  ```bash
  $ ldd a.out
  linux-vdso.so.1 =>  (0x00007ffdee334000)
  libc.so.6 => /lib64/libc.so.6 (0x00007f1e01eb3000)
  /lib64/ld-linux-x86-64.so.2 (0x00007f1e02280000)
  ```

  第一列：程序需要依赖什么库
  第二列: 系统提供的与程序需要的库所对应的库
  第三列：库加载的开始地址

- paping/psping

  PsPing 是微软 PSTools 工具套件中的其中一个命令。除了ICMP ping 测试，它主要用来测试 TCP 端口的连通性，还可以测试 TCP/UDP 网络时延和带宽。不过，PsPing 只能在 Windows 中运行。PaPing 是一个跨平台的开源工具。它的功能相对 PsPing 而言更简单，只支持 TCP 端口的相关测试，不支持 UDP 端口的测试。

- sudo
  sudo 执行的话，他的依赖信息是在 `/etc/sudoers` 里，可以通过 `sudo -V` 查看详情信息
  所以要想要一样的 ENV 的话，可以
  ```bash
  $ sudo env "PATH=$PATH" godi_console
  ```
  或者修改 sudoers 里 `Defaults secure_path = ...`
  虽然通过看文档，我认为 sudo -E 也是可行的，未测试
