Things about ssl ...

#### CSR

Certificate Signing Request

是发送到签发机构签发证书的
> a block of encrypted text

CSR 会包含在证书中，以及嵌入(embedded)在公钥中

#### SAN

subject alternative names

允许用户为单一证书添加多个域名，可以取代通用证书

一般是在 multi-domain 的情况下使用，可以指定多个域名

#### SAN 和 CN 区别

CN 只能通过通配符制定
SAN 可以指定的是 list，并且 CA/B 论坛强制 SAN 中可以包含 CN 的写法

所以 SAN 可以替代 CN 咯

#### RSA2 & RSA

- RSA2
    SHA256WithRSA
    强制要求 RSA 密钥的长度至少为 2048

- RSA
    SHA1WithRSA
    对 RSA 密钥的长度不限制，推荐使用 2048 位以上
