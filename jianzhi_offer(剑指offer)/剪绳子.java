// 描述
// 给你一根长度为 n 的绳子，请把绳子剪成整数长的 m 段（ m 、 n 都是整数， n > 1 并且 m > 1 ， m <= n ），每段绳子的长度记为 k[1],...,k[m] 。请问 k[1]*k[2]*...*k[m] 可能的最大乘积是多少？例如，当绳子的长度是 8 时，我们把它剪成长度分别为 2、3、3 的三段，此时得到的最大乘积是 18 。

// 数据范围： 2 \le n \le 602≤n≤60
// 进阶：空间复杂度 O(1)O(1) ，时间复杂度 O(n)O(n)
// 输入描述：
// 输入一个数n


import java.util.*;

public class Solution {
    private int best(int n, int m){
        //int piece = (int)Math.ceil(n*1.0/m);
        int piece = (int)(n*1.0/m)+1;
        int diff = piece*m-n;
        return (int) (Math.pow(piece,m-diff) * Math.pow(piece-1, diff));
    }
    public int cutRope (int n) {
        /* 已知 算术-几何平均值不等式： 几何平均数 <= 算术平均数
         在给定 m 的情况下可以猜出最优解
         然后我们枚举所有的 m \in [1,n] 即可
         */
        int res = 1;  // when m = n
        for(int i = 2; i < n; ++i){
            res = Math.max(res, best(n, i));
        } return res;
    }
}
