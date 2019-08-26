## SMO

$$(K_{11}+K_{22}-2K_{12})\alpha_2$$

$$ = K_{11}\zeta y_2-K_{12}\zeta y_2- y_1y_2+1+v_1y_2-v_2y_2 $$

$$ = y_{2}(K_{11}\zeta - K_{12}\zeta - y_1 + y_2 + v_1-v_2) $$

$$ = y_{2}\{ \zeta ( K_{11} - K_{12} ) + y_2 - y_1 + v_1 - v_2\} $$

因为①$v_i = g(x_i) - \Sigma_{j=1}^{2}\alpha_jy_jK_{ij} - b$, ②$\zeta = \alpha_1y_1+\alpha_2y_2$, ③$E_i=g(x_i)-y_i$

带入上式得到：

$$(K_{11}+K_{22}-2K_{12})\alpha_2^{new,unc}$$

$$ = y_{2}\{ \zeta ( K_{11} - K_{12} ) + y_2 - y_1 + (g(x_1)-g(x_2)-\alpha_1y_1K_{11}-\alpha_2y_2K_{12}+\alpha_1y_1K_{12}+\alpha_2y_2K_{22} )\} $$

$$ = y_{2}\{ \zeta ( K_{11} - K_{12} ) + (g(x_1)- y_1) - (g(x_2)- y_2) -\alpha_1y_1K_{11}-\alpha_2y_2K_{12}+\alpha_1y_1K_{12}+\alpha_2y_2K_{22} \} $$

$$ = y_{2}\{ \zeta ( K_{11} - K_{12} ) + (E_1 - E_2)-\alpha_1y_1K_{11}-\alpha_2y_2K_{12}+\alpha_1y_1K_{12}+\alpha_2y_2K_{22} \} $$

$$ = y_{2}\{(E_1 - E_2)+ (\alpha_1y_1+\alpha_2y_2)( K_{11} - K_{12} )-\alpha_1y_1K_{11}-\alpha_2y_2K_{12}+\alpha_1y_1K_{12}+\alpha_2y_2K_{22} \} $$

$$ = y_{2}\{(E_1 - E_2)+ (\alpha_1y_1K_{11}+\alpha_2y_2K_{11}-\alpha_1y_1 K_{12}-\alpha_2y_2K_{12}  )-\alpha_1y_1K_{11}-\alpha_2y_2K_{12}+\alpha_1y_1K_{12}+\alpha_2y_2K_{22} \} $$

$$ = y_{2}\{(E_1 - E_2)+ (\alpha_2y_2K_{11}-2\alpha_2y_2K_{12}+\alpha_2y_2K_{22}) \} $$

$$ = y_{2}(E_1 - E_2)+ \alpha_2(K_{11}-2K_{12}+K_{22}) $$

记$\eta = K_{11}-2K_{12}+K_{22}$, 带入上式得到：

$$\alpha_2^{new,unc} = \dfrac{y_2(E_1-E_2)}{\eta} + \alpha_2^{old}$$