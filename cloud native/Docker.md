Docker
===



**Namespace 做隔离，Cgroups 做限制，rootfs 做文件系统**



### 网络部分

单机通讯：veth pair 网卡，一端插在 docker0，一段插在容器的网络中
