[TOC]

# 逻辑回归 (Logistic Regression)

作者：豆苗 日期：2019.3.20

## sigmoid函数的来历是什么？

### 从几率 (odds) 上理解

(1) 一个事件的几率（odds）是指该事件发生的概率 ($p$)与该事件不发生的概率 (1-$p$) 的比值：$\dfrac{p}{1-p}$

该事件的对数几率（log odds），或者称为logit函数是：

$$ logit(p) = log\dfrac{p}{1-p}$$

(2) 我们记$y$ 满足$ y = logit(p) = log\dfrac{p}{1-p}$ ，可以解出$p = \dfrac{e^y}{1+e^y} = \dfrac{1}{1+e^{-y}}$。

这样一来，其实我们就得到了**sigmoid**函数！所以sigmoid其实就是**用对数几率去表示事件发生的概率$p$**。

(3) 再来看看逻辑回归，当 $P(y=1|x, \Theta) = \dfrac{1}{1+e^{-\Theta ^{T}x}}$ 时，$P(y=0|x, \Theta) = \dfrac{e^{-\Theta^{T}x}}{1+e^{-\Theta ^{T}x}}$

此时$log\dfrac{P(y=1|x, \Theta)}{P(y=0|x, \Theta)}  = log  (e^{\Theta^{T} x}) = \Theta^{T} x$

所以我们可以得出，事件的对数几率是输入特征向量$x$的线性函数。逻辑回归的目标就是学习$\Theta$，使得$\Theta^T x$拟合事件发生的对数几率logit。



### 从指数族分布族上理解

**备注: 这小节我不是很理解，总结自网络上的博客**

首先给出指数分布族的公式$p(y|\eta)=b(y)exp(\eta^T T(y) − \alpha(\eta))$，其中$\eta$是指数族的自然参数 (natural parameter)，$b(y)$和$\alpha(\eta)$可以理解为关于$y$和$\eta$的函数。

逻辑回归处理得是二分类问题，可以认为函数的概率服从伯努利分布：$p(y) = p^y(1-p)^{1-y}$

我们将其写成指数族分布的形式：

$p(y) = p^y(1-p)^{1-y} \\= exp[ylog(p)]exp[(1-y)log(1-p)] \\= exp[ylog(p)+(1-y)log(1-p)] \\= exp[log(\dfrac{p}{1-p})y + log(1-p)]$

对比上面的指数族公式，我们可以发现：

 $$b(y) = 1$$

$$ \eta = log(\dfrac{p}{1-p}) $$

$$T(y) = y$$

$$ \alpha(\eta) = -log(1-p)$$

我们从自然参数$\eta$的表达式中解出概率值$p$：$p=\dfrac{e^\eta}{1+ e^\eta} = \dfrac{1}{1+ e^{-\eta}} $

到这里我们就解出了sigmoid函数的表达式了，也就是通过指数族的自然参数$\eta$来表示概率值$p$。

参考博客：
[逻辑回归里的sigmoid函数是何方神圣？](https://blog.csdn.net/weixin_37749881/article/details/79844016)

[LR（逻辑回归） 为什么使用sigmoid函数](https://blog.csdn.net/a1628864705/article/details/62233395)

## sigmoid函数的性质

sigmoid函数的表达式为：$\sigma (x) = \dfrac{1}{1+e^{-x}}$

sigmoid函数的定义域为$[-\infty, +\infty]$, 值域为$[0, 1]$刚好对应了概率的取值！并且该函数关于$[0, \frac{1}{2}]$中心对称。

sigmoid函数的导函数为：

$$ \sigma '(x) = \dfrac{e^{ -x}}{ (1+e^{ -x})^2 } \\ =  \dfrac{1}{1+e^{-x}} \times \dfrac{ e^{  -x} }{1+e^{-x}} \\ =\sigma (x) \times (1-\sigma (x))$$

这个导函数的性质使得导数值的计算比较方便，只需要一次减法和一次乘法。

通过观察导函数可以发现，在$\sigma (x)$取值接近0或者1的时候，函数的导数值趋近于0. 

而在$\sigma (x)$的取值接近$\frac{1}{2}$，也就是$x=0$附近时函数的导数值最大，函数变化较快。

## Logistic Regression的定义

我们的训练集为$\{(x^{(i)}, y^{(i)}) \}$，其中每个样本的输入特征 $x^{(i)} \in R^{n}$, 对应的标签$y^{(i)} \in \{0, 1\}$，$i \in [1, m]$代表训练数据集大小为$m$。

逻辑回归的模型 (model) 可以表示为：$\hat{y} = \sigma(\Theta^Tx+b) = \dfrac{1}{1+e^{-(\Theta^{T}x+b)}}$，代表预测样本$x$的标签为1的概率；1-$ \hat{y} $代表了预测样本的标签为0的概率。



## 损失函数 (Loss Function)

### 均方误差？

对于一般的回归任务，我们会采用均方误差 (mean squared error, MSE) 来作为损失函数。

$MSE(y, \hat{y}) = \dfrac{1}{2m}\sum_{i=1}^{m}(y^{(i)} - \hat{y}^{(i)})^{2}$，其中$y$为样本真实的标签，$m$为样本的个数。但是MSE在采用sigmoid函数作为输出概率预测值的逻辑回归模型中是非凸函数，因此使用梯度下降法优化时容易陷入局部最优值。

现在我们通过导函数来研究一下使用MSE时的凸性。在这里我们忽略样本$m$个数，并且将输入特征向量$x \in R^n$的维度$n$限定为1。


$$\dfrac{\part(MSE)}{\part{\Theta} } = -(y-\hat{y})\hat{y}(1-\hat{y})x = -x\left[\hat{y}^3 -(1+y)\hat{y}^2 + y\hat{y}\right] $$

$$\dfrac{\part^2(MSE)}{\part{\Theta }^2} = x^2(3\hat{y}^2- 2(1+y)\hat{y} + y)\hat{y}(1-\hat{y})$$

$$\dfrac{\part^2(MSE)}{\part{b }^2} = (3\hat{y}^2- 2(1+y)\hat{y} + y)\hat{y}(1-\hat{y})$$

二次导数均不能保证大于等于0， 所以不是凸函数。而对于一般情况下的维度$n$（$n \ge 1$），证明凸性需要研究hessian matrix，这里就不展开讲了。

另一方面，虽然逻辑回归的名字中有“回归”两个字，但其实这是个用来做分类的模型。

### 交叉熵！

事实上，逻辑回归模型选择使用的策略（strategy），即目标函数是交叉熵 (cross entropy) :

$L(y, \hat{y}) = -ylog(\hat{y}) - (1-y)log(1-\hat{y})$

为了让模型的表达更简洁，我们记$\tilde{x} = [x_0, x_1, ..., x_n]^T = \begin{bmatrix} 1\\ x \end{bmatrix}$， $\tilde{\Theta}= [\Theta_0, \Theta_1, ..., \Theta_n]^T  = \begin{bmatrix} \Theta_0\\ \Theta \end{bmatrix}$，其中$\Theta_0 = b$. 此时$\tilde{x} \cdot \tilde{\Theta}=\Theta^{T}x+b $。

这样我们可以将逻辑回归的模型更加紧凑的表述为：$\hat{y} = \dfrac{1}{1+e^{-\tilde{\Theta}^{T}\tilde{x}} }$

下面我们来证明使用交叉熵损失函数时，逻辑回归模型的损失函数是凸函数。

首先求解损失函数$L$的梯度：

$\nabla L =  \left[ \dfrac{-y}{\hat {y}} + \dfrac{1- y}{1- \hat {y}} \right]\hat y(1-\hat y)(\tilde x) =(\hat y-  y) \tilde x  =(\hat y- y) \begin{bmatrix} 1 \\  x_1\\  x_2\\ ...\\  x_n \end{bmatrix} = \begin{bmatrix} \dfrac{\part L}{\part \Theta_0} \\ \dfrac{\part L}{\part \Theta_1}\\ \dfrac{\part L}{\part \Theta_2}\\ ...\\ \dfrac{\part L}{\part \Theta_n} \end{bmatrix}$

再求解损失函数$L$的Hessian Matrix：

 $\nabla^2 L  =\begin{bmatrix} \dfrac{\part^2 L}{\part  \Theta_0^2}& ... &\dfrac{\part^2 L}{\part \Theta_0 \part \Theta_n} \\ \dfrac{\part^2 L}{\part \Theta_1 \part \Theta_0}& ... &\dfrac{\part^2 L}{\part \Theta_1 \part \Theta_n} \\ \dfrac{\part^2 L}{\part \Theta_2\part  \Theta_0} & ... & \dfrac{\part^2 L}{\part \Theta_2\part \Theta_n}\\  ...&...&...\\ \dfrac{\part^2 L}{\part \Theta_n \part  \Theta_0} & ... &\dfrac{\part^2 L}{\part \Theta_n^2} \end{bmatrix}     = \hat y(1-\hat y)\begin{bmatrix} x_0x_0 & x_0x_1 & ... &x_0x_n \\  x_1x_0 & x_1x_1 & ... &x_1x_n \\  x_2x_0 & x_2x_1 & ...& x_2x_n \\ ...&...&...& ...\\  x_nx_0 & x_nx_1 & ... & x_nx_n  \end{bmatrix} = \hat y(1 -\hat y)\tilde x \tilde{x}^T \in R^{(n+1)}$

即$\nabla^2 L _{i,j} = \dfrac{\part^2 L}{\part  \Theta_i  \Theta_j}=\hat y(1-\hat y)x_ix_j$,  $where \ i,j = 0, ... ,n.$

此时 $\forall v\in R^{(n+1)} , v \ne 0 $，

满足条件$$ v^T \{ \nabla^2 L\} v = \hat y(1-\hat y) v^T\tilde x \tilde x^Tv = \hat y(1-\hat y) \begin{vmatrix} \tilde x^Tv\end{vmatrix}^2 \gt 0$$

所以我们证明了$\nabla^2 L \succ 0$，即$\nabla^2 L $是个正定矩阵，因此损失函数$L$是个凸函数。
当我们考虑样本个数$m$时，上述证明凸性的推导过程也是类似的。或者我们可以简单的利用一种保凸运算，即凸函数的非负加权求和也是凸函数来证明。对于有$m$个样本时的损失函数为：

$L(y, \hat{y}) = -\dfrac{1}{m}\sum _{i=1}^{m} \left[ y^{(i)}log(\hat{y}^{(i)}) + (1-y^{(i)})log(1-\hat{y}^{(i)}) \right]$

每个样本$(y^{(i)}, x^{(i)})$的损失函数都是凸函数，我们对每个样本利用$\dfrac{1}{m}$来加权，此时得到的损失函数依然是凸函数。

因为损失函数是凸函数，所以只要梯度为0的点就是全局最优值，此时可以通过随机梯度下降法（sgd）来求解最优值。

### 从训练模型的难度来看

除了上面分析的凸性，还有另一个原因让我们选择了交叉熵作为损失函数。首先观察均方损失函数（MSE）和交叉熵对参数$\Theta$的一阶导数：

$$\dfrac{\part(MSE)}{\part{\Theta} } = (\hat y- y )\hat{y}(1-\hat{y})x  $$

$$\dfrac{\partial L}{\partial \Theta}= ( \hat y - y)\tilde{x} $$

因为我们采用的是sigmoid函数，所以模型的预测值$\hat y \in [0, 1]$。此时可以发现对于MSE来说，当$\hat y$的值接近0或者1时，都会导致一阶导数值趋近于0。因此，当我们使用**基于梯度的迭代法**（e.g. sgd）求解模型时，模型的训练非常缓慢。相对的，采用交叉熵损失函数时就不存在这个问题。

## 模型的训练

### 迭代法

这里先讲一下常用的基于梯度的迭代求解LR模型参数的方法。我们会尽量让LR模型向量化，因为向量化可以充分利用硬件的计算资源（针对矩阵的乘法有成熟的并行计算的优化方式，写多重for循环利用不到这些优化）。这里的向量化有两层含义，第一层是针对参数$\Theta$（如果不进行向量化需要循环$n$次计算$\sum_{i=1}^{n}\Theta_ix_i$，相比计算$\Theta^T x$慢很多） ，第二层是针对样本个数$m$。

这里的符号系统参考deeplearning.ai的深度学习专项课程。每个样本的特征向量是列向量，向量化多个样本时使用horizontal的方法进行拼接：$X = \left[\tilde x^{{(1)}}, \tilde x^{{(2)}}, ..., \tilde x^{{(m)}}  \right] \in R^{(n+1) \times m}$。同样的，我们也将所有样本的标签进行向量化：$Y = [y^{(1)}, y^{(2)}, ..., y^{(m)}]$，注意$Y$是个行向量。根据上文我们对交叉熵损失函数的研究，可以知道逻辑回归的梯度为：

$\nabla L = \frac{1}{m}\sum_{i=1}^{m}(\hat y^{(i)}-  y^{(i)}) \tilde x^{(i)} $

$= \frac{1}{m}\sum_{i=1}^{m}(\sigma(\Theta^Tx^{(i)}) -  y^{(i)}) \tilde x^{(i)}$

$= \frac{1}{m}X(\sigma(\Theta^TX)-Y)^T $

$= \frac{1}{m}X(\sigma(X^T\Theta)-Y^T)$ ，

其中$\sigma(M)_{i, j}=\sigma(M_{i, j})$，就是对矩阵$M$中的每个元素$M_{i, j}$都使用一次$\sigma$函数进行非线性变换。

这之后我们使用梯度下降法在每次迭代中调整参数: 

$\tilde \Theta := \tilde \Theta - \lambda \nabla L$，其中$\lambda$是学习率/步长。

备注：关于这个模型怎么能够比较容易的想到这种向量化的方式，我觉得有个$\sum$求和的操作就要往行、列向量点积的方向去考虑。

P.P.S. 最后我们再回顾一下线性回归（Linear Regression）梯度的公式：

$\nabla L =  \frac{1}{m}\sum_{i=1}^{m}(\hat y^{(i)}-  y^{(i)}) \tilde x^{(i)} =  \frac{1}{m}\sum_{i=1}^{m}(\Theta^Tx^{(i)}-  y^{(i)}) \tilde x^{(i)} \\ =  \frac{1}{m}X(\Theta^TX-Y)^T =  \frac{1}{m}X(X^T\Theta-Y^T)$

可以看出来结果非常类似，仅仅是少了激活函数$\sigma $的操作。


## 与最大熵模型的联系？（TBD）



## Softmax回归

### 定义

softmax回归解决的是多分类（multi-class）的任务。我们的训练集为$\{(x^{(i)}, y^{(i)}) \}$，其中每个样本的输入特征 $x^{(i)} \in R^{n}$, 对应的标签$y^{(i)} \in \{1, 2,..., K\}$，$i \in [1, m]$代表训练数据集大小为$m$。为了之后简洁地表示模型，我们记$\tilde{x} = [x_0, x_1, ..., x_n]^T = \begin{bmatrix} 1\\ x \end{bmatrix}\in R^{n+1} $，我们把$y^{(i)}$通过one-hot方式编码为列向量：$\tilde y^{(i)}_j =1 $ if $y^{(i)} = j$, otherwise $\tilde y^{(i)}_j =0 $ 。为了符号的简洁，下文中我省略了符号上方的$\sim$ 。

softmax回归的模型（model）/ 假设函数定义为：

$h_\Theta(x) = \begin{bmatrix} \hat y_1 \\ \hat y_2 \\ ... \\ \hat y_K\end{bmatrix} = \dfrac{1}{\sum_{k=1}^{K}e^{\Theta_k^Tx} }\begin{bmatrix} e^{\Theta_1^Tx} \\ e^{\Theta_2^Tx} \\ ... \\ e^{\Theta_K^Tx}\end{bmatrix}$，所以我们要学习的参数就是$\Theta =[ \Theta_1, \Theta_2, ..., \Theta_K] \in R^{  (n+1)\times K}$

模型采用的损失函数是交叉熵：

$L =-\frac{1}{m}\sum_{i=1}^{m}\sum_{k=1}^{K}y_k^{(i)}log(\hat y_k^{(i)})$

$=-\frac{1}{m}\sum_{i=1}^{m}\sum_{k=1}^{K}y_k^{(i)}log\left ( \dfrac{ e^{\Theta_k^Tx}}{\sum_{l=1}^{K} e^{\Theta_{l}^Tx}} \right) $

最后我有个不成熟的感觉，单单从假设函数的定义上来看，softmax回归就是一个one-vs-all的多分类模型。

### 模型参数的梯度

我们记$z_j = \Theta_j^Tx$，接下来计算$\dfrac{\partial \hat y_k}{\partial z_j} $，这里要分情况进行讨论：

（1）$j \ne k$ 时，$\dfrac{\partial \hat y_k}{\partial z_j} = \dfrac{-e^{z_k}e^{z_j}}{ (\sum_{l=1}^{K} e^{z_l})^2} = - \hat y_k\hat y_j$

（2）$ j  = k$ 时，$\dfrac{\partial \hat y_k}{\partial z_k} = \dfrac{e^{z_k}(\sum_{l=1}^{K} e^{z_l})-e^{z_k}e^{z_k}}{ (\sum_{l=1}^{K} e^{z_l})^2} = \hat y_k -(\hat y_k)^2  = \hat y_k(1-\hat y_k)$

则$\dfrac{\partial L}{\partial z_j} = -\frac{1}{m}\sum_{i=1}^{m}\sum_{k=1}^{K}y_k^{(i)}\dfrac{\partial log(\hat y_k^{(i)})}{\partial \hat y_k^{(i)}}\dfrac{\partial \hat y_k^{(i)}}{\partial z_j}$

$= -\frac{1}{m}\sum_{i=1}^{m} \left \{\sum_{k=1, k\ne j}^{K}\left(-\dfrac{ y_k^{(i)} }{ \hat y_k^{(i)}}  \hat y_k^{(i)}\hat y_j^{(i)} \right) + \left(\dfrac{ y_j^{(i)} }{ \hat y_j^{(i)}}\hat y_j^{(i)}(1-\hat y_j^{(i)}) \right) \right \}$ 

$= -\frac{1}{m}\sum_{i=1}^{m} \left \{\sum_{k=1, k\ne j}^{K}\left(- y_k^{(i)}  \hat y_j^{(i)} \right) + \left( y_j^{(i)} (1-\hat y_j^{(i)}) \right) \right \}$ 

$= -\frac{1}{m}\sum_{i=1}^{m} \left \{ y_j^{(i)} + \hat y_j^{(i)}( -\sum_{k=1, k\ne j}^{K}  y_k^{(i)}   - y_j^{(i)})  \right \}$ 

$= -\frac{1}{m}\sum_{i=1}^{m} \left \{y_j^{(i)} - \hat y_j^{(i)}( \sum_{k=1}^{K}  y_k^{(i)}  )  \right \}$ 

$= \frac{1}{m}\sum_{i=1}^{m}(\hat y_j^{(i)} - y_j^{(i)} )$ 

则$\dfrac{\partial L}{\partial \Theta_j} = \dfrac{\partial L}{\partial z_j}\dfrac{\partial z_j}{\partial \Theta_j}   = \frac{1}{m}\sum_{i=1}^{m}(\hat y_j^{(i)} - y_j^{(i)} ) x^{(i)}$ 

又因为$\hat y^{(i)} = [\hat y_1^{(i)}, \hat y_2^{(i)}, ..., \hat y_K^{(i)}]^T$，可以得到：$\dfrac{\partial L}{\partial \Theta}  = \frac{1}{m}\sum_{i=1}^{m}x^{(i)}(\hat y^{(i)} - y^{(i)} )^T $ 

我们现在进一步**向量化**上式，还是上文中提到的思想，见到$\sum$就往点积上考虑。按照向量化多个样本时使用horizontal的方法进行拼接：记 $ Y = [y^{(1)}, y^{(2)}, ..., y^{(m)}] \in R^{K \times m}$, $\widehat Y = [\hat y^{(1)}, \hat y^{(2)}, ..., \hat y^{(m)}] \in R^{K \times m}$，$X = [x^{(1)}, x^{(2)}, ..., x^{(m)} ] \in R^{(n+1) \times m}$。

最终可以得到：$\dfrac{\partial L}{\partial \Theta}  = \frac{1}{m}\sum_{i=1}^{m}x^{(i)}(\hat y^{(i)} - y^{(i)} )^T = \frac{1}{m}[x^{(1)}, x^{(2)}, ..., x^{(m)} ] \begin{bmatrix} (\hat y^{(1)} - y^{(1)})^T \\ (\hat y^{(2)} - y^{(2)})^T \\ ... \\ (\hat y^{(m)} - y^{(m)})^T\end{bmatrix} = \frac{1}{m}X(\widehat Y - Y)^T$ 

且$\widehat Y = [h_{\Theta}(\Theta^T x^{(1)}), h_{\Theta}(\Theta^T x^{(2)}),...,h_{\Theta}(\Theta^T x^{(m)})]$。

在这里我们停顿一下，稍微对比一下逻辑回归的梯度，就可以看出两者的形式完全一致。

### 与Logistic Regression的联系

《统计学习方法》上介绍了一种多项逻辑回归的模型，对于$k$个分类的任务只有$(k-1)$个$\Theta_i$，而softmax回归有$k$个$\Theta_i $。因此多项逻辑回归模型似乎与softmax 回归不一样。其实我们想一下，对于二分类任务，逻辑回归只用到一个$\Theta$，是不是对于$K$个分类的任务，$K-1$个$\Theta$也是足够的？这就要提到softmax回归模型参数的冗余问题。

[ufldl](http://ufldl.stanford.edu/wiki/index.php/Softmax%E5%9B%9E%E5%BD%92)上提到softmax回归参数是存在冗余的，他们举了一个例子：

$\hat y_k = \dfrac{ e^{(\Theta_k - \psi )^Tx}}{\sum_{l=1}^{K} e^{(\Theta_{l}- \psi)^Tx}}  = \dfrac{ e^{\Theta_k^Tx}}{\sum_{l=1}^{K} e^{\Theta_{l}^Tx}} $, 也就是说当$\Theta = [\Theta_1, \Theta_2, ..., \Theta_K]$是模型的最优解时，对于任意的$\psi$，$\Theta^* = [\Theta_1-\psi, \Theta_2-\psi, ..., \Theta_K-\psi]$也是模型的最优解。因此也就说明了softmax回归模型中存在冗余的参数（过度参数化）。

当我们令$\psi = \Theta_K$时，$\Theta^* = [\Theta_1-\Theta_K, \Theta_2-\Theta_K, ..., \Theta_{K-1}, \overrightarrow 0]$，最后一个参数向量固定为零向量。此时模型中就只有$K-1$个$\Theta$，可以表示为：

$\hat y_j = \left\{  \begin{matrix}  \dfrac{ e^{\Theta_j^Tx} } {\sum_{l=1}^{K-1} e^{\Theta_{l}^Tx}+1}, && j = 1, 2, ..., K-1 \\   \dfrac{ 1}{\sum_{l=1}^{K-1} e^{\Theta_{l}^Tx}+1}, && j = K \end{matrix} \right. $

这就得到了多项逻辑回归的表达式，因此多项逻辑回归于softmax回归是等价的。当我们令$K=2$时，上述的多项逻辑回归就是逻辑回归，所以softmax 回归是 logistic 回归的一般形式。

## 逻辑回归是线性模型么？

逻辑回归最终得到的决策边界是线性的（只有关于$x_i$的一次项）：

$预测的类别 =\left \{  \begin{matrix} 1, && \tilde \Theta^T\tilde x \ge 0 \\ 0, && \tilde \Theta^T\tilde x \lt 0 \end{matrix} \right .$

我觉得判断模型是不是线性的，要区分回归任务和分类任务：回归的时候就看假设函数$h_\theta(x)$是不是线性函数就行了；分类的时候看决策边界是不是线性的。
上述两种情况，我们都是考察有没有$x$的组合（$x^2, x_1x_2$这类$x$的高次项就是$x$的组合），没有的话就是线性的。

## 参考资料

- 《统计学习方法》

- 吴恩达coursera上的机器学习课程《machine learning》，提到LR采用MSE导致问题非凸。

- 吴恩达deeplearning.ai深度学习专项（Deep Learning Specialization），我参考了符号以及如何向量化LR。

- 《Convex Optimization》附录 A.4.3 二阶导数

- *[Regularized Logistic Regression is Strictly Convex](http://qwone.com/~jason/writing/convexLR.pdf)*, Jason D. M. Rennie

   这里的误差函数不太理解；可以参考证明凸函数的过程。

- [逻辑斯蒂回归（Logistic Regression，LR）及其损失函数（包含凸性推导）](https://blog.csdn.net/alwaysyxl/article/details/82881272)  只有维度$n$是1的证明

- the equivalence of logistic regression and maximum entropy models 最大熵与逻辑回归的等价性[参考博客](https://blog.csdn.net/buring_/article/details/43342341)

- 《百面机器学习》 神经网络输出层是sigmoid或者softmax时不要使用均方误差

- http://ufldl.stanford.edu/wiki/index.php/Softmax_Regression softmax回归“冗余”的参数集

- https://zhuanlan.zhihu.com/p/27223959 softmax回归的梯度与参数训练