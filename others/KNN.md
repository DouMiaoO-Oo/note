# K最近邻 (KNN，k-nearest neighbors )

## kd-tree

算法流程

（1）在 kd 树中找出包含目标点 x 的叶结点：从根结点出发，递归地向下访问树。若目标点 x 当前维的坐标小于切分点的坐标，则移动到左子结点，否则移动到右子结点，直到子结点为叶结点为止；

（2）将叶节点插入”当前 K 近邻点集“；

（3）递归地向上回退，在每个结点进行以下操作：

 （a）如果”当前 K 近邻点集“元素数量小于K或者当前节点距离小于”当前 K 近邻点集“中最远点距离，那么将该节点插入”当前 K 近邻点集“，

 （b）检查当前节点的另一子结点对应的区域是否与以目标点为球心、以目标点与于”当前 K 近邻点集“中最远点间的距离为半径的超球体相交。如果相交，可能在另一个子结点对应的区域内存在距目标点更近的点，移动到另一个子结点 . 接着，递归地进行最近邻搜索；如果不相交，向上回退；

（4）当回退到根结点时，搜索结束，最后的”当前 K 近邻点集“即为 x 的 K 近邻点集。

总结查找kd树的过程：

**先左（右）子节点 → 当前节点 → 最后检查与右（左）节点的区间是否有交集，再决定是否遍历该子节点**



## 参考资料

这些除了第一个的代码，其他的我都没有仔细看

https://sine-x.com/statistical-learning-method/#%E7%AC%AC3%E7%AB%A0-k%E9%82%BB%E8%BF%91%E7%AE%97%E6%B3%95  #第3章-k邻近算法
https://blog.csdn.net/v_JULY_v/article/details/8203674
https://blog.csdn.net/winter_evening/article/details/70196080
https://www.cnblogs.com/90zeng/p/kdtree.html
https://www.cnblogs.com/zjh225901/p/7635651.html