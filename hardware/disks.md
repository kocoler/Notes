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