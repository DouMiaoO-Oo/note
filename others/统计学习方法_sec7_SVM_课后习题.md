- **7.3** 线性支持向量机还可以定义为以下形式:

$$\min_{w,b,\xi}{\frac{1}{2}\|w\|^2}+C\sum^N_{i=1}\xi_i^2 \\ s.t.{\quad}y_i(w{\cdot}x_i+b) \ge 1-\xi_i, \, i=1,2,\cdots, N \\ \xi_i \ge 0,\, i=1,2, \cdots , N​$$

试求其对偶形式。

**解答**：定义拉格朗日函数

$$ L(w,b, \xi, \alpha, \mu) = \frac{1}{2}\|\,w \|^2  +C\sum_{i=1}^{N}\xi_i^{2} - \sum_{i=1}^{N}\alpha_i(y_i(w \cdot x_i +b) - 1+ \xi_i) - \sum_{i=1}^{N}\mu_i\xi_i​$$
其中 $\alpha_i \ge 0, \mu_i \ge 0​$.

求偏导:
$$ \dfrac{\partial{L}}{\partial{w}} = w - \sum_{i=1}^{N}\alpha_iy_ix_i​$$ 
$$ \dfrac{\partial{L}}{\partial{b}} = - \sum_{i=1}^{N}\alpha_iy_i​$$
$$ \dfrac{\partial{L}}{\partial{\xi_i}} = 2C\xi_i - \alpha_i - \mu_i​$$  

令偏导为0，可以得到：
$$ w = \sum_{i=1}^{N}\alpha_iy_ix_i​$$ 
$$\sum_{i=1}^{N}\alpha_iy_i = 0​$$
$$ \alpha_i + \mu_i = 2C\xi_i​$$

带回$L​$中可得：

$$ L= \frac{1}{2}\sum_{i=1}^{N} \sum_{j=1}^{N}(\alpha_i\alpha_j y_i y_j x_{i}\cdot x_{j}) \\+ C\sum_{i=1}^{N}\xi_i^{2} \\ - \sum_{i=1}^{N}(\alpha_iy_i(\sum_{j=1}^{N}\alpha_jy_jx_j \cdot x_i ))  \\ - b\sum_{i=1}^{N}\alpha_iy_i  \\ -\sum_{i=1}^{N}\alpha_i(-1 + \xi_i) \\ - \sum_{i=1}^{N}\mu_i\xi_i ​$$ 

$$ = -\frac{1}{2}\sum_{i=1}^{N} \sum_{j=1}^{N}(\alpha_i\alpha_j y_i y_j x_{i}\cdot x_{j})  \\ + \sum_{i=1}^{N}\alpha_i \\ + C\sum_{i=1}^{N}\xi_i^{2} -\sum_{i=1}^{N}\alpha_i \xi_i  - \sum_{i=1}^{N}\mu_i\xi_i​$$

$$ = -\frac{1}{2}\sum_{i=1}^{N} \sum_{j=1}^{N}(\alpha_i\alpha_j y_i y_j x_{i}\cdot x_{j})  \\ + \sum_{i=1}^{N}\alpha_i \\ - C\sum_{i=1}^{N}\xi_i^{2}​$$