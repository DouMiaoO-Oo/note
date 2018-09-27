#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
#include <cmath>
using namespace std;

int cnt_k(int x, int k){
   int cnt = 0;
   while(x != 0){
        if(x%10 == k) ++cnt;
        x /= 10;
   } return cnt;
}
int count_k(int n, int k){
    // assert(n>=0)
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += cnt_k(i, k);
    } return ans;
}
int my_pow(int base, int exponent){
    /* 自己撸一个快速幂 */
    int res = 1;
    while(exponent != 0){
        if(exponent&1 == 0){
            base *= base;
            exponent >> 1;
        } else{
            res *= base;
            --exponent;
        }
    } return res;
}
/*
pow函数会有精度的丢失
*/
class Count2 {
public:
    /* 剑指offer上有个题是计算1的个数，与这道题类似
    我们可以把这个题泛化一下，计算任意数字k出现的次数
    思路：
    */
    int cntNumberK(int n, int k, int d){
        // int t = pow(10, d-1);  // 1000.. // 会丢失精度 https://ideone.com/GjAbJq
        int t = pow(static_cast<float>(10), static_cast<float>(d-1));  // 1000..
        cout << "t: " << t << endl;
        int msd = n/t;  // most significant digit
        int rest = n-msd*t;
        int ans;
        if(msd > k) ans = t;
        else if(msd == k) ans = rest+1;
        else ans = 0;
        // cout << "a: " << ans << endl;
        ans += msd* t/10 *(d-1);
        // cout << "b: " << ans << endl;
        if(d>1) ans += cntNumberK(rest, k, d-1);
        return ans;
    }
    int countNumberOf2s(int n) {
        // assert(n >= 0)
        int digit_cnt = 0;
        int t = n;
        while(t!=0){
            ++digit_cnt;
            t /= 10;
        }
        return cntNumberK(n, 2, digit_cnt);
    }
};

int main(){
    //int a = pow(10, 2);  // 会丢失精度
    // int a = pow(static_cast<float>(10), static_cast<float>(2)); // 不会丢失精度
    int x;
    while(cin >> x){
     	cout << "Recursive method:" << Count2().countNumberOf2s(x) << endl;
        cout << "Iteration method: " << count_k(x, 2) << endl;
    }
    return 0;
}
