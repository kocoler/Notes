
![图 1](https://i.imgur.com/v1NKRBF.png)  

![图 2](https://i.imgur.com/Ke8UrRr.png)  


- LSTM
  语言模型 捕捉 语言的潜在空间
  根据已有条件数据(N) 生成第 N+1 个字符
  character-level neural language model
  - 贪婪采样
  - 随机采样
    Softmax 温度

计算基准方法：
平均绝对误差（MAE）
MAE = np.mean(np.abs(preds - targets))

