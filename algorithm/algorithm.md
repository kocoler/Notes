### 双向 BFS

因为单 BFS 的递归树太大了
所以双向 BFS 大大减少递归树

### 摩尔投票算法
candidate
count

若 count 为 0，则 candidate = num[i]
否则 count ++ / --

遍历结束之后，如果数组中存在主要元素，则 candidate 即为主要元素，否则 candidate 可能为数组中的任意一个元素。

所以需要二次验证，再次遍历

### 康托展开

快速计算排列第 x 位
双射，所以可逆运算
