### RAID (redundant array of independent disks)

磁盘冗余阵列

- RAID 0
  两块盘（因为安全性差，不建议多盘）
  加速（并行）
  MySQL Slave(数据库的从库)，集群的节点RS

- RAID 1
  两块盘
  同等备份，速度慢一点
  单独的，数据很重要，且不能宕机的业务，监控，系统盘

- RAID 0 1
  四块盘，两块一组，一组 0 一组 1
  速度快，稳定性高
  普遍
  性能和冗余要求很好的业务。数据库主库和存储的主节点。

- RAID 5
  不指定奇偶盘，交叉存储 奇偶校验 和 校验信息
  尝试恢复
  一般的业务都可以用

### IOPS (Input/Output Per Second)
每秒的输入输出量（或读写次数）


### 队列深度

磁盘的 队列深度 是在存储器上一次可排队等待的 I/O 请求数量

这个玩意 有个最优的深度，再深性能就不会再继续上升了
可以通过增加 LUN(Logical Unit Number, 逻辑单元) 的数量来提高深度（因为 SATA 的 HDD 的队列深度是有限的嘛）

加大磁盘队列深度就是让磁盘不断工作，减少磁盘的空闲时间。


### SCSI, ATA, SATA, SAS, IDE

- SCSI

  Small Computer System Interface 小型计算机系统接口

  电脑和外设 物理连接和传送数据 的标准

  define: commands, protocols, electricald optical and logical interfaces

- ATA

  Advanced Technology Attachment 高级技术附件

  出了 SATA 之后就变成 PATA 啦
  这个应该线比较粗诶，因为 SATA 的特点是比较细 ... 可以联想很多(0x 年的电脑，拆开不认识，原来大概是 PATA)

  大概和 IDE 是一个？
  > https://en.wikipedia.org/wiki/Parallel_ATA#IDE_and_ATA-1

- SAS

  串行 SCSI

- SATA

  串行 ATA

SATA 和 SAS 兼容的哦


### NVMe

非易失性内存表达
基于 PCIe

能够处理 65000 的队列深度
