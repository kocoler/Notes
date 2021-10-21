#### 流程

迭代：
1. 根域名（.）
2. 顶级域名
3. 具体的域名服务器
递归：
DNS 服务器帮忙查询，查询到了，就返回，没查询到，就继续查询

#### 胶水记录

在查询域名的同时会返回下一级 DNS 服务器的 IP 地址

#### DNS zone transfer

是一种 DNS 事务
就是说 DNS 跨越很多歌 DNS 服务器（across a set of DNS servers）备份（快速迁移）数据库（记录）的时候用到的
是 **AXFR** 记录
由于查询返回的响应比较大，*对于数据的准确有着较强的需求*，使用 TCP 协议

#### DNS 与 UDP

> DNS 解析器或者服务器在发送非区域传输查询时，必须先发送一个 UDP 查询，如果该查询的响应被截断，它应该尝试使用 TCP 协议重新请求；

EDNS 为 DNS 提供了扩展功能，让 DNS 通过 UDP 协议携带最多 4096 字节的数据；

当客户端接收到一个被截断的 DNS 响应时，应该通过 TC 字段判断是否需要通过 TCP 协议重复发出 DNS 查询请求；

DNSSEC 的引入使得截断的 UDP 数据包变得非常常见；

所有通用 DNS 实现必须要同时支持 UDP 和 TCP 传输协议，其中包括权威服务器、递归服务器以及桩解析器；

桩解析器和递归解析器可以根据情况选择使用 TCP 或者 UDP 查询直接请求目标服务器，以 UDP 协议来开始发起 DNS 请求不再是强制性的，TCP 协议与 UDP 协议在 DNS 查询中可以互相替代，而不是作为重试机制；

=> dns over udp/tcp/tls/http/https

#### EDNS

Extension Mechanisms for DNS (EDNS)

add OPT header

ref: https://draveness.me/whys-the-design-dns-udp-tcp/
