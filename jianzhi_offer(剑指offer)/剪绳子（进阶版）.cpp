/*
给你一根长度为 n 的绳子，请把绳子剪成整数长的 m 段（ m 、 n 都是整数， n > 1 并且 m > 1 ， m <= n ），每段绳子的长度记为 k[1],...,k[m] 。请问 k[1]*k[2]*...*k[m] 可能的最大乘积是多少？例如，当绳子的长度是 8 时，我们把它剪成长度分别为 2、3、3 的三段，此时得到的最大乘积是 18 。

由于答案过大，请对 998244353 取模。
*/

#include <cmath>

/*
可以证明 (n/m)^m 次方在 n/m=e 时取得最大值
所以 n/m 等于 3 时可以取得最大值
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param number long长整型 
     * @return long长整型
     */
    
    long long cutRope(long long number) {
        if(number == 2 || number == 3) return number-1;
        long long times = 0;
        if(number % 3 == 0) {
            times = number/3;
            return f(times);
        }
        else if (number % 3 == 1) {
            number -= 4;
            times = number/3;
            return f(times)*2*2 % 998244353;
        }
        else {  // number % 3 == 2
            times = number/3;
            return f(times)*2 % 998244353;
        }
    }
private:
    long long f(long long exp){
        // 3^(exp) % 998244353
        long long res = 1;
        long long base = 3;
        while(exp != 0){
            if((exp & 1) == 1){
                res = (res*base)%998244353;
            } 
            base = (base*base)%998244353;
            exp /= 2;
        }
        return res;
    }
};
