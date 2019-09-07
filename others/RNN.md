

![img](./RNN/RNN-cell.png) 

注：下文中的$$g(\cdot)$$ 代表某种激活函数，可以是$$sigmoid, tanh, relu$$等等。

$$a^{⟨0⟩} $$ 一般初始化为0， 即$$a^{⟨0⟩} = \vec{0}$$ 。模型也不是在每个时刻$$t$$都需要有输出，因此$$\hat y^{⟨t⟩}$$可能不是在每个时刻下都存在。例如，对于句子分类任务，可能只有在最后一个时刻才有一个代表类别标签的输出；而在机器翻译任务中，可能每个时刻下都会有一个输出$$\hat y^{⟨t⟩}$$。该模型的误差是所有输出时刻的交叉熵。

**前向传播：**

$$a^{⟨t⟩} = g_1(W_{aa}a^{⟨t-1⟩} + W_{ax}x^{⟨t⟩} + b_a)$$

$$\hat y^{⟨t⟩} = g_2(W_{ya}a^{⟨t⟩} + b_y)$$

为了进一步简化公式以方便运算，可以将 $W_{ax}$、$W_{aa}$水平拼接(horizontal stack)为一个矩阵 $W_a$，同时 $a^{⟨t-1⟩}$和 $ x^{⟨t⟩}$ **堆叠**成一个矩阵。则有：

$$W_a = [W_{ax}, W_{aa}]$$

$$a^{⟨t⟩} = g_1(W_a[a^{⟨t-1⟩}, x^{⟨t⟩}] + b_a)$$

$$\hat y^{⟨t⟩} = g_2(W_{y}a^{⟨t⟩} + b_y)$$

**反向传播:**



Reference:

- https://github.com/Kulbear/deep-learning-coursera

- [某人的笔记](https://github.com/bighuang624/Andrew-Ng-Deep-Learning-notes/blob/master/docs/Sequence_Models/%E5%BE%AA%E7%8E%AF%E5%BA%8F%E5%88%97%E6%A8%A1%E5%9E%8B.md)
- [循环神经网络（一般RNN）推导](https://blog.csdn.net/dchen1993/article/details/53885490)
- [RNN以及LSTM的介绍和公式梳理](https://blog.csdn.net/Dark_Scope/article/details/47056361)