MESI协议
===

缓存一致性命名都是状态命名(Modified, Exclusive, Shared, Invalid)

**已修改Modified (M)**
缓存行是脏的（dirty），与主存的值不同。如果别的CPU内核要读主存这块数据，该缓存行必须回写到主存，状态变为共享(S).
**独占Exclusive (E)**
缓存行只在当前缓存中，但是干净的（clean）--缓存数据同于主存数据。当别的缓存读取它时，状态变为共享；当前写数据时，变为已修改状态。
**共享Shared (S)**
缓存行也存在于其它缓存中且是干净的。缓存行可以在任意时刻抛弃。
**无效Invalid (I)**
缓存行是无效的

![图 2](https://i.loli.net/2021/10/08/XVdYIMyrw9PlkWT.png)  


