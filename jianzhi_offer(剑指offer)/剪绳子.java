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
