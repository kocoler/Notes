### 高级向量扩展指令集（Advanced Vector Extensions, AVX）

> 是x86架构微处理器中的指令集

> AVX是X86指令集的SSE延伸架构，如IA16至IA32般的把寄存器XMM 128bit提升至YMM 256bit，以增加一倍的运算效率。此架构支持了三运算指令（3-Operand Instructions），减少在编码上需要先复制才能运算的动作。在微码部分使用了LES LDS这两少用的指令作为延伸指令Prefix。

> AVX2指令集将大多数整数命令操作扩展到256位，并引入了熔合乘法累积（FMA）运算。AVX-512则使用新的EVEX前缀编码将AVX指令进一步扩展到512位。Intel Xeon Scalable处理器支持AVX-512。

