[TOC]

# 一元线性回归

这个小节也可以称为（一元）最小二乘法的**代数解法**。

希望拟合出的函数: $ \hat{y} = ax+b ​$, 其中$a, b​$为学习的一元函数的参数.<br></br>
误差函数: $ J = \frac{1}{2} \sum_{i=1}^{n}(y_i -\hat{y_i})\ = \frac{1}{2} \sum_{i=1}^{n}(y_i - ax_i -b)^2​$，其中$n​$是样本的个数.

对误差函数求导: <br></br>
$$ \frac{\partial{J}}{\partial{a}} = -\sum_{i=1}^{n}(y_i - ax_i -b)x_i$$

$$ \frac{\partial{J}}{\partial{b}} = -\sum_{i=1}^{n}(y_i - ax_i -b)$$ 

令误差函数为0: <br></br>
$$ \frac{\partial{J}}{\partial{a}}=0 \Rightarrow a\sum_{i=1}^{n}x_{i}^{2} + b\sum_{i=1}^{n}x_i = \sum_{i=1}^{n}x_iy_i $$

$$ \frac{\partial{J}}{\partial{b}}=0 \Rightarrow a\sum_{i=1}^{n}x_{i} + bn = \sum_{i=1}^{n}y_i $$

为了方便计算我们记 $A = \sum_{i=1}^{n}x_{i}^{2}$, $B = \sum_{i=1}^{n}x_{i}$, $C= \sum_{i=1}^{n}x_iy_i $, $D =  \sum_{i=1}^{n}y_i $. <br></br>
可以把上式简化为： <br></br>
$$ aA+bB = C, $$ (1) <br></br>
$$ aB+bn = D$$, (2)

化简(2)得 $b = \frac{D-aB}{n}$ , 带入(1) 得到 $anA+(D-aB)B = nC $,  <br></br>
$ \Rightarrow a = \dfrac{nC-BD}{nA-B^2}$, <br></br>
$ \Rightarrow  b = \dfrac{D(nA-B^2)-(nC-BD)B}{n(nA-B^2)} = \dfrac{AD-BC}{nA-B^2}$

综上：
$$ a = \dfrac{n\sum_{i=1}^{n}x_iy_i - \sum_{i=1}^{n}x_{i} \sum_{i=1}^{n}y_i }{n\sum_{i=1}^{n}x_{i}^2 - (\sum_{i=1}^{n}x_{i})^2}$$

$$ b = \dfrac{\sum_{i=1}^{n}x_{i}^2 \sum_{i=1}^{n}y_{i} - \sum_{i=1}^{n}x_{i} \sum_{i=1}^{n}x_{i}y_{i}}{n\sum_{i=1}^{n}x_{i}^2 - (\sum_{i=1}^{n}x_{i})^2}$$

**注：**一般情况下，最小二乘法使用的公式为：<br></br>
$$ a = \dfrac{\sum_{i=1}^{n}(X_i- \bar{X})(Y_i- \bar{Y})}{\sum_{i=1}^{n}(X_i - \bar{X})^2}$$, $$ b = \bar{Y} - a\bar{X}$$

上式使用 $\bar{X} = \sum_{i=1}^{n}X_i​$ 以及 $\bar{Y} = \sum_{i=1}^{n}Y_i​$很容易验证正确性。

**注：**此外，这种通过求导的代数解法还可以扩展到多元线性回归。



# 最小二乘法

这个小节可以称为最小二乘法的**矩阵解法**。

对于给定$A, b​$， 希望找到某个$x​$使得$Ax = \hat{b}​$对于误差$J = \frac{1}{2} (b -\hat{b})^2​$最小 ，此问题可以通过求解$ A^TAx = A^Tb​$来找到最优$x = (A^TA)^{-1}A^TB​$。这个公式有一个很简单的几何解释：优化的目标$J​$，就是$b​$到$A​$张成的平面$Ax ​$的距离。更多详细的解释请见Linear algebra and its applications, 3rd edition (ISBN: 9787121113956) 中的Sec. 6.5



# 编程题目

[编程题]线性回归 https://www.nowcoder.com/questionTerminal/9d4d2ab1cca947ec88912fc7761e537b



# 经典问题

## 线性回归的损失函数的选择

对于一元线性回归模型, 假设从总体中获取了n组观察值 $(X_1, Y_1), (X_2, Y_2), …,(X_n, Y_n)$。使用直线来拟合平面中的这$n$个点时，从直观上来考虑使用处于样本数据中心位置的直线最合理。 选择最佳拟合直线的标准可以确定为：使总的拟合误差（即总残差）达到最小。有以下三个标准可以选择：

1. 用“残差和最小”确定直线位置是一个途径。但很快发现计算“残差和”存在相互抵消的问题。
2. 用“残差绝对值和最小”确定直线位置也是一个途径。但绝对值的计算比较麻烦。
3. 最小二乘法的原则是以“残差平方和最小”确定直线位置。用最小二乘法除了计算比较方便外，得到的估计量还具有优良特性。这种方法对异常值非常敏感。

## 最小二乘法与梯度下降法

最小二乘法跟梯度下降法都是通过求导来求损失函数的最小值，那它们有什么区别呢。

**相同点：**

1.本质相同：两种方法都是在给定已知数据（independent & dependent variables）的前提下对dependent variables算出出一个一般性的估值函数。然后对给定新数据的dependent variables进行估算。

2.目标相同：都是在已知数据的框架内，使得估算值与实际值的总平方差尽量更小（事实上未必一定要使用平方），估算值与实际值的总平方差的公式为：

$ J = \frac{1}{2} \sum_{i=1}^{n}(y_i - h_{\theta}(X_i)​$

 其中$X_i$为第$i$组数据的independent variable，$y_i$为第$i$组数据的dependent variable，$\theta$为系数向量。

**不同点：**

实现方法和结果不同：最小二乘法是直接对$J​$求导找出**全局最小**，是非迭代法。而梯度下降法是一种迭代法，先给定一个$\theta​$，然后向$J​$下降最快的方向调整$\theta​$，在若干次迭代之后找到**局部最小**。

最小二乘法的缺点：

$A^TA$可能不是可逆的矩阵；对于数据点多，维度很大的$A$很难直接进行计算。

梯度下降法的缺点是到最小点的时候收敛速度变慢，并且对初始点的选择极为敏感，其改进大多是在这两方面下功夫。

## Logistic Regression 和线性回归的区别



 



# 参考文献

ref1: https://blog.csdn.net/qll125596718/article/details/8248249 一元线性回归模型与最小二乘法及其C++实现

ref2: https://www.cnblogs.com/Yiutto/p/5825498.html 最小二乘所使用的一般形式的公式

ref3: http://www.cnblogs.com/iamccme/archive/2013/05/15/3080737.html 最小二乘法与梯度下降法的关系

ref4: [最小二乘法小结](https://www.cnblogs.com/pinard/p/5976811.html)  包括最小二乘法的代数、矩阵解法，最小二乘法的局限性