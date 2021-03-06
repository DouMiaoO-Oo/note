# K最近邻 

K最近邻算法 (K近邻, KNN，k-nearest neighbors )

K值减小意味着模型变得复杂，K值增大意味着模型变得简单。K近邻模型中使用多数表决，等价于经验损失最小化。

特征值的差异很大时，绝对值大的特征更容易影响到KNN对数据集空间的划分。因此，使用KNN前需要对每种特征进行**归一化** ，尤其是在认为每种特征的重要性相同的情况下更需要进行归一化操作，以免KNN更倾向于受到绝对值大的特征的影响。



## kd-tree

算法流程

（1）在 kd 树中找出包含目标点 x 的叶结点：从根结点出发，递归地向下访问树。若目标点 x 当前维的坐标小于切分点的坐标，则移动到左子结点，否则移动到右子结点，直到子结点为叶结点为止；

（2）将叶节点插入”当前 K 近邻点集“；

（3）递归地向上回退，在每个结点进行以下操作：

 （a）如果”当前 K 近邻点集“元素数量小于K或者当前节点距离小于”当前 K 近邻点集“中最远点距离，那么将该节点插入”当前 K 近邻点集“，

 （b）检查当前节点的另一子结点对应的区域是否与以目标点为球心、以目标点与于”当前 K 近邻点集“中最远点间的距离为半径的超球体相交。如果相交，可能在另一个子结点对应的区域内存在距目标点更近的点，移动到另一个子结点 . 接着，递归地进行最近邻搜索；如果不相交，向上回退；

（4）当回退到根结点时，搜索结束，最后的”当前 K 近邻点集“即为 x 的 K 近邻点集。

**总结查找kd树的过程：**

先左（右）子节点 → 当前节点 → 最后检查与右（左）节点的区间是否有交集，再决定是否遍历该子节点。

**适用条件：**

样本的个数远大于特征维度的时候使用。



## 疑问

朴素的KNN解法需要计算新样本点与已知的所有带标签样本点的距离。

使用kd-tree在回溯祖先节点的过程中，**检查当前节点的另一子结点对应的区域是否与以目标点为球心、以目标点与于”当前 K 近邻点集“中最远点间的距离为半径的超球体相交** 这个操作是很难的，我没有想清楚到底是怎么加速的。我感觉这个子问题的判断方法与朴素KNN解法一样，这就导致我使用kd-tree的复杂度跟朴素KNN一模一样。在KD-Tree.py中判断是否相交，仅仅使用了一个维度来判断，这样判断是否相交就变得很容易了。但是这样其实是放宽了相交的条件，增大了搜索另一个子节点的可能。



## 文件列表

- KNN_kd-tree(octave参考代码).m, 来自sine(x)的博客。
- KD-Tree.py, sin(x)博客中代码的Python实现。

## 参考资料

- 《统计学习方法》
- 《机器学习实战》(《Machine Learning in Action》)，提供了KNN需要归一化的例子。

这些除了第一个的代码，其他的我都没有仔细看

https://sine-x.com/statistical-learning-method/#%E7%AC%AC3%E7%AB%A0-k%E9%82%BB%E8%BF%91%E7%AE%97%E6%B3%95  #第3章-k邻近算法
https://blog.csdn.net/v_JULY_v/article/details/8203674
https://blog.csdn.net/winter_evening/article/details/70196080
https://www.cnblogs.com/90zeng/p/kdtree.html
https://www.cnblogs.com/zjh225901/p/7635651.html