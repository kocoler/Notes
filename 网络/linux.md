常见的内网IP段有：

10、172、192 开头

- 10.0.0.0/8

  10.0.0.0 - 10.255.255.255

- 172.16.0.0/12

  172.16.0.0 - 172.31.255.255

- 192.168.0.0/16

  192.168.0.0 - 192.168.255.255

以上三个网段分别属于A、B、C三类IP地址，来自 《[RFC 1918](https://tools.ietf.org/html/rfc1918)》。

> http://tangxinfa.github.io/article/51857f51-ip-6bb5670954ea4e9b.html



在第二层上的数据，我们叫Frame，在第三层上的数据叫Packet，第四层的数据叫Segment。



### Linux 中的 TCP/IP 协议栈参数

> https://colobu.com/2014/09/18/linux-tcpip-tuning/

**/proc/sys/net/ipv4/** : TCP 的 IPV4参数，但是重启会失效

**/etc/sysctl.conf** : Linux 内核参数 sysctl -p 生效

```conf
net.ipv4.tcp_syc_retries=1
```

### 半连接队列

收到SYN包后，TCP会把SYN包放入半连接队列，等待ACK包。
