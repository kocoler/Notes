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
