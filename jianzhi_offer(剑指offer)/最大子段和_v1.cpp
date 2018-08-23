#include <iostream>
#include<vector>
using namespace std;
    int FindGreatestSumOfSubArray(vector<int> a) {
        int n = a.size();
        if(n == 0) return 0;
        else if(n == 1) return a[0];
        int res = a[0];
        for(int i = 1; i < n; ++i){
            res = max(res, a[i]);
        } if(res < 0) return res;
        vector<int> l(n, 0);
        vector<int> r(n, 0);
        l[0] = max(a[0], 0);
        r[n-1] = max(a[n-1], 0);
        int tmp;
        for(int i = 1; i < n; ++i){
            tmp = l[i-1] + a[i];
            l[i] = max(tmp, 0);
        }
        for(int i = n-2; i >= 0; --i){
            tmp =a[i]+r[i+1];
            r[i] = max(tmp, 0);
        }
        for(int i = 0; i < n-1; ++i){
            tmp = l[i] + r[i+1];
            res = max(res, tmp);
        } return res;
    }
int main(){
    int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
    //int a[] = {-1, -2, -3, -10, -4, -7, -2, -5};  // 全部为负数的样例
    int ans = FindGreatestSumOfSubArray(vector<int>(a, a+8));
    cout << ans << endl;
}
