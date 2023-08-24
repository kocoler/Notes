### 常用网络延迟优化策略：

#### 微波传输

不使用光纤，直线距离，在空气中传播，类似专线

##### InfiniBand

不在转发时实时计算转发路径，提前计算好

- 更大带宽

- 低延迟交换机
  port * port 阵列转发

- Kernel By Pass
  绕过内核处理
  ![图 1](https://i.imgur.com/4wxhdXn.png) 
  直接在用户态轮询等待用户请求

- RDMA

- TOE 硬件卸载

FPGA

- 其他硬件配置
  CPU，内存，

- 程序上
  
