UUID(Universally Unique Identifier)
===

UUID(Universally Unique Identifier): 全局唯一标识符

是指在一台机器上生成的数字，它保证对在同一时空中的所有机器都是唯一的。

按照 开放软件基金会(OSF) 制定的标准计算，用到了以太网卡地址、纳秒级时间、芯片ID码和许多可能的数字。由以下几部分的组合：当前日期和时间，时钟序列，全局唯一的IEEE机器识别号（如果有网卡，从网卡获得，没有网卡以其他方式获得），UUID的唯一缺陷在于生成的结果串会比较长。

A UUID is 128 bits long, and can guarantee uniqueness across space and time. UUIDs were originally used in the Apollo Network Computing System and later in the Open Software Foundation's (OSF) Distributed Computing Environment (DCE), and then in Microsoft Windows platforms.

GUID（Globally Unique Identifier）是UUID的别名；但在实际应用中，GUID通常是指微软实现的UUID。

Nil UUID：00000000-0000-0000-0000-000000000000

UUID Version 1：基于时间的UUID

UUID Version 2：DCE安全的UUID

UUID Version 3：基于名字的UUID（MD5）

UUID Version 4：随机UUID

UUID Version 5：基于名字的UUID（SHA1）



在线uuid：http://www.uuid.online/

生成uuid：

```bash
$ uuidgen
```



ref：

- http://blog.chinaunix.net/uid-26495963-id-3150576.html