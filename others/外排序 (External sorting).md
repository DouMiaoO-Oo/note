# 外排序

外排序就是在内存不够存下所有待排序数据时，利用外部存储（e.g. 硬盘）来进行排序的一种方法。

## 外归并排序

假设我们有B个可用的内存页（page），需要排序的有N个数据页。排序的方法如下：

（1）第0遍处理：每次读入内存中B个数据页，并且对这B个数据页进行内部排序，然后写回外部存储。我们称每次写回外部存储的有序数据为段（run），第0遍处理时总共能生成$\left\lceil N/B\right\rceil​$个段，每个段包含B个数据页（最后一个段内包含的数据页可能小于B）。我们定义$N^* = \left\lceil N/B\right\rceil​$。

（2）第i遍处理（i=1, 2, ..., $\left\lceil log_{B-1}(N^*)\right\rceil ​$）：用B-1个内存页从外部存储读取输入，也就是每个内存页读取一个有序的段，剩下一个内存页用来做merge排序并且输出到外部存储中。这样可以同时归并排序B-1个数据段。

因此，在完成外归并排序时，总共需要处理1+$\left\lceil log_{B-1}(N^*)\right\rceil ​$遍数据。

### 例子

假设内存（主存，缓冲区）有5个数据页，需要对108个页的数据进行排序。

第0遍处理：$\left\lceil 108/5\right\rceil=22​$个有序段。

第1遍处理：$\left\lceil  log_{4}(22)\right\rceil=6$个有序段。

第2遍处理：$\left\lceil  log_{4}(6)\right\rceil=2$个有序段。

第3遍处理：$\left\lceil  log_{4}(2)\right\rceil=1$个有序段。

我们处理了4遍数据，也就是进行了$4*108*2$=864次 IO操作。

## 其他方法TBD

万一有了再补充吧。

## 参考资料

- 《数据库管理系统原理与设计》 译者: 周立柱 / 张志强 / 李超 / 王煜
- *Database Management Systems*  by Raghu Ramakrishnan and Johannes Gehrke
- https://en.wikipedia.org/wiki/External_sorting