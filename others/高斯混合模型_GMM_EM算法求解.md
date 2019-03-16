# 一维高斯混合模型 (GMM)

前言：Gaussian Mixture Model(GMM)原始的E步是$E_{\gamma}(f) = \sum_{\gamma}f(\gamma)\times p(\gamma)$这种形式的。这里的$\gamma \in R^{N \times K}$是个随机向量，$f: R^{N \times K} \rightarrow R$是个函数映射。求E步时，当我们交换了求和的顺序之后，可以发现每个$f$是个随机变量$\gamma_{jk}$。 于是我们有了下面的讨论。



对于$n​$维随机向量$X \in R^{n} ​$，他的期望被定义为：

$ E_{X} = \sum_{X} X \times P(X) = \begin{bmatrix} E_{X_1} \\ E_{X_2} \\ ...\\ E_{X_n} \end{bmatrix}$

所以对于每个维度的随机变量$X_i$关于$X$的期望： $\sum_X X_i \times P(X) = E_{X_i}$  可以发现就是$E_{X_i}$ 这个结论在之后会用到。



（1）《统计学习方法》书上的方法

$E_{\gamma} \left \{ \sum_{k=1}^{K} \sum_{j=1}^{N} \gamma_{jk} \left[ log(\alpha_{k}) + log\dfrac{1}{\sqrt{2\pi}}  -  log\sigma_k  - \dfrac{1}{2\sigma_k^2}(y_j - \mu_k)^2  \right] \right \}​$

$ = \sum_{\gamma}P(\gamma | y, \theta^{(i)}) \left \{ \sum_{k=1}^{K} \sum_{j=1}^{N} \gamma_{jk} \left[ log(\alpha_{k}) + log\dfrac{1}{\sqrt{2\pi}}  -  log\sigma_k  - \dfrac{1}{2\sigma_k^2}(y_j - \mu_k)^2  \right] \right \}​$

$ = \sum_{k=1}^{K} \sum_{j=1}^{N}   \left \{ \left[ log(\alpha_{k}) + log\dfrac{1}{\sqrt{2\pi}}  -  log\sigma_k  - \dfrac{1}{2\sigma_k^2}(y_j - \mu_k)^2  \right]  \textcolor{red}{ \sum_{\gamma} P(\gamma| y_j, \theta^{(i)})  \gamma_{jk} } \right \}​$

根据之前的结论可以知道  $\sum_{\gamma} P(\gamma| y_j, \theta^{(i)}) \gamma_{jk}  = E(\gamma_{jk}|  y_j, \theta^{(i)} )  $，所以上式可以进一步表示为：

$ \sum_{k=1}^{K} \sum_{j=1}^{N}   \left \{ \left[ log(\alpha_{k}) + log\dfrac{1}{\sqrt{2\pi}}  -  log\sigma_k  - \dfrac{1}{2\sigma_k^2}(y_j - \mu_k)^2  \right] \textcolor{red}{ E(\gamma_{jk} | y_j, \theta^{(i)})}  \right \}  $



（2）现在我们用另一种思路来处理上面的过程 ：

$\gamma= (\gamma_{jk}) \in R^{N \times K}​$ 是个随机向量。对于每个样本$j​$，我们定义随机向量$\gamma_{j} \in R^{K}, \gamma_{j} = [\gamma_{j1}, \gamma_{j2}, ..., \gamma_{jK}]^T​$

根据GMM的定义，$\gamma _{j}​$ 是个one-hot向量。因此对于 $i​$-th维度是1的$\gamma_{j}​$满足：

$P(\gamma_{j} ) = P(\gamma_{ji} = 1, \gamma_j其他维度为0) = \prod_{k=1}^{K}P(\gamma_{jk}=1)^{ \gamma_{jk} } = P(\gamma_{ji}=1)​$ 

所以$\sum_{\gamma} f(\gamma)P(\gamma) = \sum_{k=1}^{K} f(\gamma)P(\gamma_{ji}=1)$.  

有了上面的基本概念，我们再来推导GMM的E步：

$E_{\gamma} \left \{ \sum_{k=1}^{K} \sum_{j=1}^{N} \gamma_{jk} \left[ log(\alpha_{k}) + log\dfrac{1}{\sqrt{2\pi}}  -  log\sigma_k  - \dfrac{1}{2\sigma_k^2}(y_j - \mu_k)^2  \right] \right \}​$

$ = \sum_{j=1}^{N} \sum_{k=1}^{K}    \left \{ \left[ log(\alpha_{k}) + log\dfrac{1}{\sqrt{2\pi}}  -  log\sigma_k  - \dfrac{1}{2\sigma_k^2}(y_j - \mu_k)^2  \right]  \textcolor{red}{ \sum_{\gamma}  P(\gamma | y_j, \theta^{(i)})   \gamma_{jk} } \right \}​$

我们来看上式中的$\sum_{\gamma}  P(\gamma | y_j, \theta^{(i)})   \gamma_{jk}​$ 套用之前提到的概念可以改写为：

$\sum_{\gamma}  P(\gamma | y_j, \theta^{(i)})   \gamma_{jk} = \sum_{l=1}^{K} P(\gamma_{jl} = 1 | y_j, \theta^{(i)})  \gamma_{jk}​$

因为$\gamma_j$是个one-hot向量，所以只有当$l = k$时（也就是选择第$k$个维度是1的$\gamma $），$\gamma_{jk}$才等于1，此时 $P(\gamma_{jl} = 1 | y_j, \theta^{(i)})  \gamma_{jk}$才不为0。

因此我们可以得到： $\sum_{\gamma}  P(\gamma | y_j, \theta^{(i)})   \gamma_{jk} =  P(\gamma_{jk}=1 | y_{j}, \theta^{(i)})   \gamma_{jk} = P(\gamma_{jk}=1 | y_{j}, \theta^{(i)})  ​$

综上：

$E_{\gamma} \left \{ \sum_{k=1}^{K} \sum_{j=1}^{N} \gamma_{jk} \left[ log(\alpha_{k}) + log\dfrac{1}{\sqrt{2\pi}}  -  log\sigma_k  - \dfrac{1}{2\sigma_k^2}(y_j - \mu_k)^2  \right] \right \}$

$ = \sum_{j=1}^{N} \sum_{k=1}^{K}    \left \{ \left[ log(\alpha_{k}) + log\dfrac{1}{\sqrt{2\pi}}  -  log\sigma_k  - \dfrac{1}{2\sigma_k^2}(y_j - \mu_k)^2  \right]  \textcolor{red}{ P(\gamma_{jk}=1 | y_{j}, \theta^{(i)})  } \right \}​$

此时我们得到了与《统计学习方法》书中一致的结果。

## 参考资料

- 《统计学习方法》李航

-  [Multivariate random variable](https://en.wikipedia.org/wiki/Multivariate_random_variable#Expected_value )  wiki上关于随机向量期望的介绍

