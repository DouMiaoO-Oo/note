# pLSA

$d_i$是代表$i$-th文档 (document), $P(d_i)$代表选择文档$d_i$的概率；$w_j$代表词典 (vocabulary) 中$j$-th个词 (term)，$P(w_j|d_i)$代表选中文档$d_i$后，再选择词$w_j$的概率。$n(w_j, d_i)$代表文档$d_i$中词$w_j$出现的个数，$n(d_i)$代表文档$d_i$中包含词的个数。$N$和$M$分别代表文档总数和词典中不同词的个数。

Note：$ P(d_i)​$只跟文档$d_i​$中词的个数有关，就是文档$d_i ​$的总词数$n(d_i )​$比全部文档的总词数$\sum_i n(d_i) ​$。

对于上述定义，我们可以得到似然函数：

$$ L = \prod _{i = 1}^{N} \prod_{j=1}^{M} (p(w_j|d_i)p(d_i))^{n(d_i, w_j)} ​$$

对数似然函数为：

$$ logL = \sum _{i = 1}^{N} \sum_{j=1}^{M} n(d_i, w_j) log(p(w_j|d_i)p(d_i)) ​$$

## pLSA模型的定义

模型 probabilitistic Latent Semantic Analysis (pLSA) 引入了一个称为主题的隐变量$Z$。pLSA把每篇文档当成了主题的多项分布，每个主题当成是词汇的多项分布。$z_k$代表了$k$-th主题，$P(z_k|d_i)$代表了文档$d_i$选择主题$z_k$的概率，$P(w_j|z_k)$代表了从主题$z_k$中选择$w_j$的概率。$K$代表了我们设置的主题的总个数。

pLSA中定义文档的生成过程，可以描述为：

(1) 以$P(d_i)​$ 的概率选中文档$d_i​$;

(2) 以$P(z_k|d_i)​$的概率选中主题$z_k​$;

(3) 以$P(w_j|z_k)​$的概率产生一个单词$w_j​$。

上述过程的似然函数为：

$$ L = \prod _{i = 1}^{N} \prod_{j=1}^{M} [ p(wj|di)p(di) ] ^{n(d_i, w_j)} ​$$

$$= \prod _{i = 1}^{N} \prod_{j=1}^{M} \left \{ \left [ \sum_{k=1}^{K}P(w_j|z_k)P(z_k|d_i) \right ]  p(di) \right \} ^{n(d_i, w_j)}  $$

对数似然函数为：

$$ logL = \sum _{i = 1}^{N} \sum_{j=1}^{M} n(d_i, w_j) log \left ( \sum_{k=1}^{K} \left [ P(w_j|z_k)P(z_k|d_i) \right ]  p(d_i) \right ) ​$$

$$= \sum _{i = 1}^{N} \sum_{j=1}^{M} n(d_i, w_j) log \left ( \sum_{k=1}^{K}  \left [P(w_j|z_k)P(z_k|d_i) \right ]  \right )  + \textcolor{red}{ \sum _{i = 1}^{N} \sum_{j=1}^{M} n(d_i, w_j) log\left ( p(d_i)  \right) } $$

## EM算法求解pLSA

我们希望极大化$logL$，需要估计的参数是$P(z_k| d_i)$和$P(w_j|z_k )$。所以$logL \propto  \sum _{i = 1}^{N} \sum_{j=1}^{M} n(d_i, w_j) log \left ( \sum_{k=1}^{K}  \left [P(w_j|z_k)P(z_k|d_i) \right ]  \right ) $, 也就是去掉了上式$logL$中$\textcolor{red}{红色}$的部分。

这个似然函数不好计算，所以得用EM算法求解。

### E步

#### 从对数似然函数$logL$到$Q$函数

运用EM算法的思想，我们构造可以利用Jenson不等式的式子：

$ \sum _{i = 1}^{N} \sum_{j=1}^{M} n(d_i, w_j) log \left ( \sum_{k=1}^{K}  \left [P(w_j|z_k)P(z_k|d_i) \right ]  \right ) ​$

$ = \sum _{i = 1}^{N} \sum_{j=1}^{M} n(d_i, w_j) log \left ( \sum_{k=1}^{K}  \dfrac{\left [ \textcolor{red}{P^{old}(z_k| w_j, d_i)} P(w_j|z_k)P(z_k|d_i) \right ]} {\textcolor{red}{P^{old}(z_k| w_j, d_i)} }  \right ) ​$

其中的$\textcolor{red}{红色}​$字体 $P^{old}(z_k| w_j, d_i) = \dfrac{P^{old}( w_j|z_k) P^{old}(z_k|d_i)}{\sum_{k=1}^{K}P^{old}( w_j|z_k) P^{old}(z_k|d_i) }​$。

Note：$P^{old}​$为上一轮迭代估计到的参数值，所以当前轮极大化$logL​$时，认为$P^{old}​$为常数而非需要估计的参数。

因为满足$\sum_{k=1}^{K}P^{old}(z_k| w_j, d_i) = 1$且$log$是严格凹函数, 可以对上式运用Jenson不等式：

$$ \sum _{i = 1}^{N} \sum_{j=1}^{M} n(d_i, w_j) log \left ( \sum_{k=1}^{K}  \dfrac{\left [ \textcolor{red}{P^{old}(z_k| w_j, d_i)} P(w_j|z_k)P(z_k|d_i) \right ]} {\textcolor{red}{P^{old}(z_k| w_j, d_i)} }  \right ) ​$$

$$\ge \sum _{i = 1}^{N} \sum_{j=1}^{M} n(d_i, w_j) \sum_{k=1}^{K} \textcolor{red}{P^{old}(z_k| w_j, d_i)}log \left (   \dfrac{\left [  P(w_j|z_k)P(z_k|d_i) \right ]} {\textcolor{red}{P^{old}(z_k| w_j, d_i)} }  \right ) ​$$

$$ = \sum _{i = 1}^{N} \sum_{j=1}^{M} n(d_i, w_j) \sum_{k=1}^{K} \textcolor{red}{P^{old}(z_k| w_j, d_i)}log \left (   \left [  P(w_j|z_k)P(z_k|d_i) \right ]  \right )     - \sum _{i = 1}^{N} \sum_{j=1}^{M} n(d_i, w_j) \sum_{k=1}^{K} \textcolor{red}{P^{old}(z_k| w_j, d_i)}log \left (   \textcolor{red}{P^{old}(z_k| w_j, d_i)}   \right ) ​$$

去掉上式中的常数项第二项，我们就得到了$Q​$函数：$Q(\Theta, \Theta^{old}) = \sum _{i = 1}^{N} \sum_{j=1}^{M} n(d_i, w_j) \sum_{k=1}^{K} \textcolor{red}{P^{old}(z_k| w_j, d_i)}log \left (   \left [  P(w_j|z_k)P(z_k|d_i) \right ]  \right )  ​$,

其中的$\Theta = \{P(z_k|d_i), P(w_j|z_k)\}​$, 到此时我们就完成了pLSA的**E步**。



#### $log(P(Z, W| D))$怎么计算？

看了《统计学习方法》，我总认为应该先求出complete data (可观测变量$X$, 隐变量$Z$, 参数$\Theta$) 的对数联合概率$log(X, Z|\Theta)$，再去求解期望$E_z[log(X, Z|\Theta) | X^{old}, \Theta^{old}]$。但事实上，还是应该按照上一个小节那样，①先定义出$log(P(X|\Theta))$; ②构造新式子并运用Jenson不等式。因为很多时候可能不太容易直接写出$log(X, Z|\Theta)$。

不过这里我还是想讨论一下pLSA中$ log(P(W, D, Z|\Theta))​$的求解方法。注意，下文我使用的符号为$w_l​$。对于文档$d_i​$ 来说，$w_l ​$是文档$d_i​$中的$l​$-th位置上的词。区分一下上文pLSA论文中的符号$w_j ​$，代表了词典中第$j​$个词。

根据上文pLSA中生成一个文档的定义，我们可以认为确定了一个文档$d_i$和该文档中的一个词$w_{l} $， 就能确定出从文档中生成$w_l$的主题$z$, 也就是$(d_i, w_j) \rightarrow z$; 也可以认为在确定了文档$ d_i $之后，每次生成$z $再生成$ w_l $的过程都是独立同分布 (i.i.d)的; 也就是每个$z$只与对应的$d_i$和$w_l$有关，而与其他所有的随机变量无关。

于是有了下面的公式：

$ log(P(W, D, Z)) = \sum_{i = 1}^{N} \sum_{l=1}^{n(d_i)} log \left ( P(w_l|z)P(z|d_i) P(d_i) \right )$

$= \sum_{i = 1}^{N} \sum_{l=1}^{n(d_i)} log \left ( P(w_l|z)P(z|d_i)\right ) +  \textcolor{red}{\sum_{i = 1}^{N}log P(d_i)}  $

注：这里的$z$可以认为受到$w_l$与$d_i$的约束，或者我们可以认为$z$其实是$z_{l, i}$。

去掉与极大化无关的$\textcolor{red}{常数部分}$，可以得到$ log(P(W, D, Z)) \propto \sum_{i = 1}^{N} \sum_{l=1}^{n(d_i)} log \left ( P(w_l|z)P(z|d_i)\right ) = logP(W, Z|D)$

对$log(P(W, Z|D))​$求关于$Z|W, D​$ 的期望：

$\sum_{k=1}^{K} P(z_k | W, D) \sum_{i = 1}^{N} \sum_{l=1}^{n(d_i)} log \left ( P(w_l|z_k)P(z_k|d_i)\right )$

$=  \sum_{i = 1}^{N} \sum_{k=1}^{K}  \sum_{l=1}^{n(d_i)}P(z_k | w_l, d_i) log \left ( P(w_l|z_k)P(z_k|d_i)\right )​$

$=  \sum_{i = 1}^{N} \sum_{k=1}^{K}  \textcolor{red}{\sum_{j=1}^{M}n(w_j, d_i)} P(z_k | \textcolor{red}{w_j}, d_i) log \left ( P(\textcolor{red}{w_j}|z_k)P(z_k|d_i)\right )$

至此，我们又将$Q$函数推导了出来！



#### 关于Q函数的疑问

这一部分是我**胡乱**写的，自己的疑问。

观察Q函数：

$ \sum_{i = 1}^{N} \sum_{j=1}^{M} n(d_i, w_j) \sum_{k=1}^{K} P(z_k|d_i, w_j) log[P(w_j|z_k) P(z_k|d_i)]​$

$= \sum_{i = 1}^{N} \sum_{j=1}^{M}  \sum_{k=1}^{K} P(z_k|d_i, w_j) \textcolor{red}{n(d_i, w_j)}log[P(w_j|z_k) P(z_k|d_i)] ​$

$= \sum_{i = 1}^{N} \sum_{j=1}^{M}  \sum_{k=1}^{K} P(z_k|d_i, w_j) log [P(w_j|z_k) P(z_k|d_i)]^{\textcolor{red}{n(d_i, w_j)}} ​$

如果去掉对$Z|W, D$求期望的部分，可以得到：

$\sum_{i = 1}^{N} \sum_{j=1}^{M}   log [P(w_j, z_|d_i)]^{\textcolor{red}{n(d_i, w_j)}} ​$

这个部分应该代表了$log(W, Z|D)$? 那么此时不就是说在$d_i$中$w_j$和$z$共现的次数都是$n(d_i,w_j)$，也就是说生成的$n(d_i,w_j)$个$w_j$都是出自同一个主题z? 

再换句话说, $d_i$中有$n(d_i, w_j)$个$w_j$，pLSA生成$w_j$的过程可以等价的理解为采样一个$z$, 再采样出$n(w_j, d_i)$个$w_j$?

### M步

等式约束下求极大值，引入拉格朗日乘子再求零点即可。

## 参考资料

- https://blog.csdn.net/yangliuy/article/details/8330640
- *Unsupervised Learning by Probabilistic Latent Semantic Analysis*
- 《统计学习方法》