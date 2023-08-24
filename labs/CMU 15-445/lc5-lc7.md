
Locks using in external system, and latches using internal.

![图 1](https://i.imgur.com/pXEurGC.png)  


Page directory needs to be durable, page tables needn't.

![图 2](https://i.imgur.com/uBdWibp.png)  


Allocation policies:
- Global policy
  Optimize for global decision.
- Local policy
  Optimize for current decision.


Buffer pool optimize. 

- Multiple buffer pools
- Pre-fetching
- Scan Sharing
- Buffer pool bypass

Data Structure:
- Internal Meta-data
- Core Data Storage
- Temporary Data Structure
- Table Indexes

### hash table

- static hashing schemes
  - linear probe
    Fill in the blanks
  - robin hood
    More balance
  - cuckoo
    Multiple hash functions

- Dynamic hashing schemes
  - Chained Hashing
  - Extendible Hashing
    Split buckets instead of letting the linked list grow forever.
    Reshuffling buckets.
    ![图 3](https://i.imgur.com/qeOenTR.png)  

  - Linear Hashing
    Split the next slot bucket.
    ![图 4](https://i.imgur.com/gY4ECs9.jpg) 
    When the 17 overflowed, add the split pointer 4, its will split every bucket eventually.

### B-Tree

Data Structures
- Internal Meta-data
- Core Data Storage
- Temporary Data Structures
- Table Indexes

![图 1](https://i.imgur.com/bGIVwbH.png)  

![图 2](https://i.imgur.com/5ToiAh8.png)  

![图 3](https://i.imgur.com/szPBYrR.png)  

![图 4](https://i.imgur.com/jXXVKIz.png)  
 
merge threshold -> could be delayed

Variable length keys
- Pointers
- Variable length nodes
- Padding
- Key Map/Indirection
  Embed an array of pointers that map to the key + value list within the node

Intra-node search
- Linear
- Binary
- Interpolation

Optimizations(for intra-node)
- Prefix Compression
- Suffix truncation
- Bulk Insert
- Pointer Swizzling

