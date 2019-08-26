## 前向分布算法与AdaBoost

Note：得到$G_m^*$的过程，优化的就是加权的，但尚未归一化的误差率。



$$ \Sigma_{i=1}^{N}\bar{w}_{mi}exp(-y_i\alpha G(x_i)) $$

$$ = \Sigma_{G(x_i)=y_i}\bar{w}_{mi}e^{-\alpha} + \Sigma_{G(x_i)\ne y_i}\bar{w}_{mi}e^{\alpha}$$

$$ = \Sigma_{i=1}^{N}\bar{w}_{mi}e^{-\alpha} -\Sigma_{G(x_i)\ne y_i}\bar{w}_{mi}e^{-\alpha}+ \Sigma_{G(x_i)\ne y_i}\bar{w}_{mi}e^{\alpha}$$

$$ = \Sigma_{i=1}^{N}\bar{w}_{mi}e^{-\alpha}+ \Sigma_{G(x_i)\ne y_i}\bar{w}_{mi}(e^{\alpha}-e^{-\alpha})$$

$$ = e^{-\alpha}\Sigma_{i=1}^{N}\bar{w}_{mi}+ (e^{\alpha}-e^{-\alpha})\Sigma_{i=1}^{N}\bar{w}_{mi}I(G(x_i)\ne y_i)$$

在上式中对$\alpha$求导并令导数为0：

$$-e^{-\alpha}\Sigma_{i=1}^{N}\bar{w}_{mi}+ (e^{\alpha}+e^{-\alpha})\Sigma_{i=1}^{N}\bar{w}_{mi}I(G(x_i)\ne y_i) = 0$$

$$\Leftrightarrow \Sigma_{i=1}^{N}\bar{w}_{mi}= (e^{2\alpha}+1)\Sigma_{i=1}^{N}\bar{w}_{mi}I(G(x_i)\ne y_i)$$

$$\Leftrightarrow e^{2\alpha} = \dfrac{ \Sigma_{i=1}^{N}\bar{w}_{mi}}{\Sigma_{i=1}^{N}\bar{w}_{mi}I(G(x_i)\ne y_i)} - 1$$

$$\Leftrightarrow e^{2\alpha} = \dfrac{ 1 - \dfrac{\Sigma_{i=1}^{N}\bar{w}_{mi}I(G(x_i)\ne y_i)}{\Sigma_{i=1}^{N}\bar{w}_{mi}} }{ \dfrac{\Sigma_{i=1}^{N}\bar{w}_{mi}I(G(x_i)\ne y_i)}{\Sigma_{i=1}^{N}\bar{w}_{mi}} }$$

我们记$e_m = \dfrac{\Sigma_{i=1}^{N}\bar{w}_{mi}I(G(x_i)\ne y_i)}{\Sigma_{i=1}^{N}\bar{w}_{mi}}$，此时上式可以表示为$e^{2\alpha} = \dfrac{1-e_m}{e_m} $

可以解出最优的$\alpha $等于$\alpha_m^* = \dfrac{1}{2}log(\dfrac{1-e_m}{e_m})$

我们观察$e_m$，可以发现$e_m$代表的刚好就是对样本加权之后的分类误差率。

