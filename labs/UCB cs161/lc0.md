## Review of cs61c

![图 1](https://s2.loli.net/2022/10/15/Ehb4Ajx6eRrFZcP.png)  

[Nibbles](https://en.wikipedia.org/wiki/Nibble): four-bit aggregation, half an octet(eight-bit)

![图 2](https://s2.loli.net/2022/10/15/mjbMI2hfUd6xPlO.png)  


X86: little-endian

![图 3](https://s2.loli.net/2022/10/15/GRZIWoF2KmJ6nqX.png)  


Stack Design:

ESP, EBP: Extended stack pointer, Extended base pointer


![图 4](https://s2.loli.net/2022/10/15/GzjDty7Z6hQWeid.png)  

Inside a struct, the variables are filled from the bottom up.

![图 5](https://s2.loli.net/2022/10/15/nNSiwzgmoCspfyE.png)  


![图 6](https://s2.loli.net/2022/10/15/j7Jz1WXxRkFtuSe.png)  

AT&T syntax vs Intel syntax:
![图 8](https://s2.loli.net/2022/10/15/2vU3CkZAqF6dzNy.png)  


![图 7](https://s2.loli.net/2022/10/15/O1xW5lcSHEGjLZb.png)  

```asm
; leave:
movl %ebp, %esp
popl %ebp

; ret:
popl %eip
```

![图 10](https://s2.loli.net/2022/10/15/XeFc2ZLwxVnsWgy.png)  

![图 9](https://s2.loli.net/2022/10/15/bLY12U5VWzItAic.png)  
