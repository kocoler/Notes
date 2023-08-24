
实现 0GC 的方案
1. 无 GC
   分配堆外内存(mmap)

2. 避免 GC
    a. map 非指针优化 (map[uint64]uint32) 或采用 slice 实现一套无指针 map
    b. 数据存入 []byte slice(可考虑底层采用环形队列封装循环使用空间)
