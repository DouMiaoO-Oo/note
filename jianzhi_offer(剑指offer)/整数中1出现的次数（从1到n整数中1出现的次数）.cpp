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
class Solution {
public:
    int cntNumberK(int n, int k, int d){
        // int t = pow(10, d-1);  // 1000.. // »á¶ªÊ§¾«¶È https://ideone.com/GjAbJq
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
    int NumberOf1Between1AndN_Solution(int n)
    {
         if(n<=0) return 0;
        int digit_cnt = 0;
        int t = n;
        while(t!=0){
            ++digit_cnt;
            t /= 10;
        }
        return cntNumberK(n, 1, digit_cnt);
    }
};
int main(){
    int x;
    while(cin >> x){
        cout << "Recursive method:"  << Solution().NumberOf1Between1AndN_Solution(x) << endl;
        cout << "Iteration method: " << count_k(x, 1) << endl;
    }
    return 0;
}
