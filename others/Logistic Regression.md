# 逻辑回归 (Logistic Regression)

## sigmoid函数的来历是什么？

### 从几率 (odds) 上理解

(1) 一个事件的几率（odds）是指该事件发生的概率 ($p​$)与该事件不发生的概率 (1-$p​$) 的比值：$\dfrac{p}{1-p}​$

该事件的对数几率（log odds），或者称为logit函数是：

$$ logit(p) = log\dfrac{p}{1-p}$$

(2) 我们记$y$ 满足$ y = logit(p) = log\dfrac{p}{1-p}$ ，可以解出$p = \dfrac{e^y}{1+e^y} = \dfrac{1}{1+e^{-y}}$。

这样一来，其实我们就得到了**sigmoid**函数！所以sigmoid其实就是**用对数几率去表示事件发生的概率$p$**。

(3) 再来看看逻辑回归，当 $P(y=1|x, \Theta) = \dfrac{1}{1+e^{-\Theta ^{T}x}}$ 时，$P(y=0|x, \Theta) = \dfrac{e^{-\Theta^{T}x}}{1+e^{-\Theta ^{T}x}}$

此时$log\dfrac{P(y=1|x, \Theta)}{P(y=0|x, \Theta)}  = log  (e^{\Theta^{T} x}) = \Theta^{T} x$

所以我们可以得出，事件的对数几率是输入特征向量$x$的线性函数。逻辑回归的目标就是学习$\Theta$，使得$\Theta^T x$拟合事件发生的对数几率logit。



### 从指数族分布族上理解

**lyw: 这小节我不是很理解，总结自网络上的博客**

首先给出指数分布族的公式$p(y|\eta)=b(y)exp(\eta^T T(y) − \alpha(\eta))​$，其中$\eta​$是指数族的自然参数 (natural parameter)，$b(y)​$和$\alpha(\eta)​$可以理解为关于$y​$和$\eta​$的函数。

逻辑回归处理得是二分类问题，可以认为函数的概率服从伯努利分布：$p(y) = p^y(1-p)^{1-y}​$

我们将其写成指数族分布的形式：

$p(y) = p^y(1-p)^{1-y} \\= exp[ylog(p)]exp[(1-y)log(1-p)] \\= exp[ylog(p)+(1-y)log(1-p)] \\= exp[log(\dfrac{p}{1-p})y + log(1-p)]​$

对比上面的指数族公式，我们可以发现：

 $$b(y) = 1​$$

$$ \eta = log(\dfrac{p}{1-p}) ​$$

$$T(y) = y$$

$$ \alpha(\eta) = -log(1-p)$$

我们从自然参数$\eta$的表达式中解出概率值$p$：$p=\dfrac{e^\eta}{1+ e^\eta} = \dfrac{1}{1+ e^{-\eta}} $

到这里我们就解出了sigmoid函数的表达式了，也就是通过指数族的自然参数$\eta$来表示概率值$p$。

参考博客：
[逻辑回归里的sigmoid函数是何方神圣？](https://blog.csdn.net/weixin_37749881/article/details/79844016)

[LR（逻辑回归） 为什么使用sigmoid函数](https://blog.csdn.net/a1628864705/article/details/62233395)

## sigmoid函数的性质

sigmoid函数的表达式为：$\sigma (x) = \dfrac{1}{1+e^{-x}}​$

sigmoid函数的定义域为$[-\infty, +\infty]​$, 值域为$[0, 1]​$刚好对应了概率的取值！并且该函数关于$[0, \frac{1}{2}]​$中心对称。

sigmoid函数的导函数为：

$$ \sigma '(x) = \dfrac{e^{ -x}}{ (1+e^{ -x})^2 } \\ =  \dfrac{1}{1+e^{-x}} \times \dfrac{ e^{  -x} }{1+e^{-x}} \\ =\sigma (x) \times (1-\sigma (x))$$

这个导函数的性质使得导数值的计算比较方便，只需要一次减法和一次乘法。

通过观察导函数可以发现，在$\sigma (x)$取值接近0或者1的时候，函数的导数值趋近于0. 

而在$\sigma (x)$的取值接近$\frac{1}{2}$，也就是$x=0$附近时函数的导数值最大，函数变化较快。

## 损失函数 (Loss Function)

逻辑回归的模型 (model) 是 $\hat{y} = \dfrac{1}{1+e^{-(\Theta^{T}x+b)}}$，代表了预测样本的标签为1的概率，则1-$ \hat{y} $代表了预测样本的标签为0的概率。

### 均方误差？

对于一般的回归任务，我们会采用均方误差 (mean squared error, MSE) 来作为损失函数。

$MSE(y, \hat{y}) = \dfrac{1}{2m}\sum_{i=1}^{m}(y_i - \hat{y}_i)^{2}​$，其中$m​$为样本的个数。但是MSE在采用sigmoid函数作为输出概率预测值的逻辑回归模型中是非凸函数，因此使用梯度下降法优化时容易陷入局部最优值。

现在我们通过导函数来研究一下使用MSE时的凸性。在这里我们忽略样本$m$个数，并且将输入特征向量$x \in R^n$的维度$n$限定为1。


$$\dfrac{\part(MSE)}{\part{\Theta} } = -(y-\hat{y})\hat{y}(1-\hat{y})x = -x\left[\hat{y}^3 -(1+y)\hat{y}^2 + y\hat{y}\right] ​$$

$$\dfrac{\part^2(MSE)}{\part{\Theta }^2} = x^2(3\hat{y}^2- 2(1+y)\hat{y} + y)\hat{y}(1-\hat{y})​$$

$$\dfrac{\part^2(MSE)}{\part{b }^2} = (3\hat{y}^2- 2(1+y)\hat{y} + y)\hat{y}(1-\hat{y})​$$

二次导数均不能保证大于等于0， 所以不是凸函数。而对于一般情况下的维度$n​$（$n \ge 1​$），证明凸性需要研究hessian matrix，这里就不展开讲了。

另一方面，虽然逻辑回归的名字中有“回归”两个字，但其实这是个用来做分类的模型。

### 交叉熵！

事实上，逻辑回归模型选择使用的策略（strategy），即目标函数是交叉熵 (cross entropy) :

$L(y, \hat{y}) = -ylog(\hat{y}) - (1-y)log(1-\hat{y})​$

为了让模型的表达更简洁，我们记$\tilde{x} = [x_0, x_1, ..., x_n]^T = \begin{bmatrix} 1\\ x \end{bmatrix}​$， $\tilde{\Theta}= [\Theta_0, \Theta_1, ..., \Theta_n]^T  = \begin{bmatrix} \Theta_0\\ \Theta \end{bmatrix}​$，其中$\Theta_0 = b​$. 此时$\tilde{x} \cdot \tilde{\Theta}=\Theta^{T}x+b ​$。

这样我们可以将逻辑回归的模型更加紧凑的表述为：$\hat{y} = \dfrac{1}{1+e^{-\tilde{\Theta}^{T}\tilde{x}} }​$

下面我们来证明使用交叉熵损失函数时，逻辑回归模型的损失函数是凸函数。

首先求解损失函数$L$的梯度：

$\nabla L =  \left[ \dfrac{-y}{\hat {y}} + \dfrac{1- y}{1- \hat {y}} \right]\hat y(1-\hat y)(\hat x) =(\hat y-  y) \hat x  =(\hat y- y) \begin{bmatrix} 1 \\  x_1\\  x_2\\ ...\\  x_n \end{bmatrix} = \begin{bmatrix} \dfrac{\part L}{\part \Theta_0} \\ \dfrac{\part L}{\part \Theta_1}\\ \dfrac{\part L}{\part \Theta_2}\\ ...\\ \dfrac{\part L}{\part \Theta_n} \end{bmatrix}$

再求解损失函数$L​$的Hessian Matrix：

 $\nabla^2 L  =\begin{bmatrix} \dfrac{\part^2 L}{\part  \Theta_0^2}& ... &\dfrac{\part^2 L}{\part \Theta_0 \part \Theta_n} \\ \dfrac{\part^2 L}{\part \Theta_1 \part \Theta_0}& ... &\dfrac{\part^2 L}{\part \Theta_1 \part \Theta_n} \\ \dfrac{\part^2 L}{\part \Theta_2\part  \Theta_0} & ... & \dfrac{\part^2 L}{\part \Theta_2\part \Theta_n}\\  ...&...&...\\ \dfrac{\part^2 L}{\part \Theta_n \part  \Theta_0} & ... &\dfrac{\part^2 L}{\part \Theta_n^2} \end{bmatrix}     = \hat y(1-\hat y)\begin{bmatrix} x_0x_0 & x_0x_1 & ... &x_0x_n \\  x_1x_0 & x_1x_1 & ... &x_1x_n \\  x_2x_0 & x_2x_1 & ...& x_2x_n \\ ...&...&...& ...\\  x_nx_0 & x_nx_1 & ... & x_nx_n  \end{bmatrix} = \hat y(1 -\hat y)\hat x \hat{x}^T \in R^{(n+1)}​$

即$\nabla^2 L _{i,j} = \dfrac{\part^2 L}{\part  \Theta_i  \Theta_j}=\hat y(1-\hat y)x_ix_j$,  $where \ i,j = 0, ... ,n.$

此时 $\forall v\in R^{(n+1)} , v \ne 0 ​$，

满足条件$$ v^T \{ \nabla^2 L\} v = \hat y(1-\hat y) v^T\hat x \hat x^Tv = \hat y(1-\hat y) \begin{vmatrix} \hat x^Tv\end{vmatrix}^2 \gt 0$$

所以我们证明了$\nabla^2 L \succ 0​$，即$\nabla^2 L ​$是个正定矩阵，因此损失函数$L​$是个凸函数。
当我们考虑样本个数$m​$时，上述证明凸性的推导过程也是类似的。或者我们可以简单的利用一种保凸运算，即凸函数的非负加权求和也是凸函数来证明。对于有$m​$个样本时的损失函数为：

$L(y, \hat{y}) = -\dfrac{1}{m}\sum _{i=1}^{m} \left[ y_ilog(\hat{y}_i) + (1-y_i)log(1-\hat{y}_i) \right]​$

每个样本$(y_i, x_i)$的损失函数都是凸函数，我们对每个样本利用$\dfrac{1}{m}$来加权，此时得到的损失函数依然是凸函数。

因为损失函数是凸函数，所以只要梯度为0的点就是全局最优值，此时可以通过随机梯度下降法来求解最优值。

### 从训练模型的难度来看

除了上面分析的凸性，还有另一个原因让我们选择了交叉熵作为损失函数。首先观察均方损失函数（MSE）和交叉熵对参数$\Theta$的一阶导数：

$$\dfrac{\part(MSE)}{\part{\Theta} } = (\hat y- y )\hat{y}(1-\hat{y})x  ​$$

$$\dfrac{\partial L}{\partial \Theta}= ( \hat y - y)\tilde{x} $$

因为我们采用的是sigmoid函数，所以模型的预测值$\hat y \in [0, 1]$。此时可以发现对于MSE来说，当$\hat y$的值接近0或者1时，都会导致一阶导数值趋近于0，使得模型的训练非常缓慢。相对的，采用交叉熵损失函数时就不存在这个问题。

## 参考资料

- 《统计学习方法》

- 吴恩达coursera上的机器学习课程《machine learning》

- 《Convex Optimization》附录 A.4.3 二阶导数

- *[Regularized Logistic Regression is Strictly Convex](http://qwone.com/~jason/writing/convexLR.pdf)*, Jason D. M. Rennie

   这里的误差函数不太理解；参考证明凸函数的过程。

- [逻辑斯蒂回归（Logistic Regression，LR）及其损失函数（包含凸性推导）](https://blog.csdn.net/alwaysyxl/article/details/82881272)  只有维度$n$是1的证明

- the equivalence of logistic regression and maximum entropy models 最大熵与逻辑回归的等价性[参考博客](https://blog.csdn.net/buring_/article/details/43342341)

- 《百面机器学习》 神经网络输出层是sigmoid或者softmax时不要使用均方误差

   