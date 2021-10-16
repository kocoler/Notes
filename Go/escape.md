逃逸分析
===

首先 go 语言的堆和栈是混在一起的

> https://github.com/golang/go/issues/30554#issuecomment-469141498

if b is a slice

b escape means b[0] ... escape

&b escape means b escape
