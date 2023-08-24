VPS 常用技术 OpenVZ、Xen、KVM

PV/HVM:
Para-virtualization (PV) or Hardware-assisted virtualization (HVM).

- OpenVZ
  操作系统级别的虚拟化技术
  易于理解，低权重开销，一般来说更优的性能
- Xen
  半虚拟化技术
  自己运行了一个内核的实例，可以自由加载内核模块，虚拟内存和 IO，稳定而且课预测
