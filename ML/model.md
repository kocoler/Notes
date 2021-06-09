### 学习方式
  - 监督式学习
    测试数据集，训练数据集，不断修正
  - 非监督
    学习模型是为了推断出数据的一些内在结构
    无特殊标注
  - 半监督
    有些标注有些不标注
    用来预测
  - 强化学习
    输入数据作为对模型的反馈 -> 强化，必须反馈
    机器人

### 算法分类
  - 回归算法
    误差均衡
    > 常见的回归算法包括：最小二乘法（Ordinary Least Square），逻辑回归（Logistic Regression），逐步式回归（Stepwise Regression），多元自适应回归样条（Multivariate Adaptive Regression Splines）以及本地散点平滑估计（Locally Estimated Scatterplot Smoothing）。
  - 基于实例算法
    对决策建模 -> 划分样本 -> 近似性匹配
    通过这种方式来寻找最佳的匹配
    > 常见的算法包括 k-Nearest Neighbor(KNN), 学习矢量量化（Learning Vector Quantization， LVQ），以及自组织映射算法（Self-Organizing Map ， SOM）。
  - 正则化算法

    > 常见的算法包括：Ridge Regression， Least Absolute Shrinkage and Selection Operator（LASSO），以及弹性网络（Elastic Net）。
  - 决策树学习
    决策树
    > 常见的算法包括：分类及回归树（Classification And Regression Tree， CART）， ID3 (Iterative Dichotomiser 3)， C4.5， Chi-squared Automatic Interaction Detection(CHAID), Decision Stump, 随机森林（Random Forest）， 多元自适应回归样条（MARS）以及梯度推进机（Gradient Boosting Machine， GBM）
  - 贝叶斯方法
    > 常见算法包括：朴素贝叶斯算法，平均单依赖估计（Averaged One-Dependence Estimators， AODE），以及Bayesian Belief Network（BBN）。
  - 基于核的算法
    映射高阶模型
    > 常见的基于核的算法包括：支持向量机（Support Vector Machine， SVM）， 径向基函数（Radial Basis Function ，RBF)， 以及线性判别分析（Linear Discriminate Analysis ，LDA)等。
  - 聚类算法
    中心 归并
    > 常见的聚类算法包括 k-Means算法以及期望最大化算法（Expectation Maximization， EM）。
  - 关联规则算法
    变量关系
    > 常见算法包括 Apriori算法和Eclat算法等。
  - 遗传算法
    它把问题可能的解编码为一个向量，称为个体，向量的每一个元素称为基因 -> 评价 -> 选择、交换、变异等遗传操作 -> 新群体
  - 人工智能神经网络
    模式匹配算法
    > 重要的人工神经网络算法包括：感知器神经网络（Perceptron Neural Network）, 反向传递（Back Propagation）， Hopfield网络，自组织映射（Self-Organizing Map, SOM）。
  - 深度学习
    人工神经网络 ++
    > 常见的深度学习算法包括：受限波尔兹曼机（Restricted Boltzmann Machine， RBN）， Deep Belief Networks（DBN），卷积网络（Convolutional Network）, 堆栈式自动编码器（Stacked Auto-encoders）。
  - 降低维度算法
    简化模型
    > 常见的算法包括：主成份分析（Principle Component Analysis， PCA），偏最小二乘回归（Partial Least Square Regression，PLS）， Sammon映射，多维尺度（Multi-Dimensional Scaling, MDS）,  投影追踪（Projection Pursuit）等。
  - 集成算法
    较弱的模型 分开 -> 集成
    > 常见的算法包括：Boosting， Bootstrapped Aggregation（Bagging）， AdaBoost，堆叠泛化（Stacked Generalization， Blending），梯度推进机（Gradient Boosting Machine, GBM），随机森林（Random Forest），GBDT（Gradient Boosting Decision Tree）


ref: https://www.cnblogs.com/maybe2030/p/4665816.html