### 可信平台模块 (Trusted Platform Module, TPM)

旨在使用设备中集成的专用微控制器（安全硬件）处理设备中的加密密钥

> 可信平台模块提供一个安全生成密钥的设施，对其使用的限制，以及一个随机数生成器。它还包括如远程认证和密封存储等能力。

比如 bitlocker 就是用的这个

### 高级配置与电源接口(Advanced Configuration and Power Interface, ACPI)

1997年由英特尔、微软、东芝共同提出、制定的操作系统电源管理、硬件配置接口，是一种开放标准.

后归 UEFI 论坛

并不都交由 BIOS 管理，使操作系统可以管理电源。

状态（越往下越省电）：
- 全局状态（S0-S0ix-S6）（G0-G3）
- 设备状态（D0-D3）电源供应
- 处理器状态（C0-Cn）决定唤醒时间
- 设备和处理器性能状态（P0-Pn）

### MBR/全局唯一标识分区表（GUID Partition Table, GPT）

MBR 所有的都记录在主引导记录里

而 GPT 分散记录，但是第一块还是 MBR（兼容性）

> 主引导记录（Master Boot Record，缩写：MBR），又叫做主引导扇区

> 为了减少分区表损坏的风险，GPT在硬盘最后保存了一份分区表的副本。

分区表头（LBA1）
分区表项（LBA 2–33）