
#### FUSE

用户空间文件系统（**F**ilesystem in **Use**rspace)
它使无特权的用户能够无需编辑内核代码而创建自己的文件系统。

#### 块存储、文件存储、对像存储

![图 16](https://s2.loli.net/2022/01/17/PMAJc4BXalT9dz8.png)  

这三种存储，分别对应了不同的访问协议，这也就决定了他们的本质差别。

文件存储，主要操作对象是文件和文件夹。
以 NFS 为例，文件相关的接口包括：LOOKUP/ACCESS/READ/WRITE/CREATE/REMOVE/RENAME 等等，文件夹相关的接口包括：MKDIR/RMDIR/READDIR 等等。同时也会有 FSSTAT/FSINFO 等接口用于提供文件系统级别的信息。POSIX，SAMBA 等也是文件存储协议。协议更注重接口的灵活，以及访问权限控制。

块存储，主要操作对象是磁盘。以 SCSI 为例，主要接口有 Read/Write/Read Capacity/Inquiry 等等。FC，iSCSI，也是块存储协议。和文件存储相比，没有文件和目录树的概念，一般协议也不会定义磁盘的创建和删除操作。协议更注重传输控制。

对象存储，主要操作对象是对象（Object）。以 S3 为例，主要接口有 PUT/GET/DELETE 等。和文件和对象存储相比，没有随机读写的接口。和文件存储相比，没有目录树的概念。协议更注重简洁。

