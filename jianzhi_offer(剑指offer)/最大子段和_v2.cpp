#include <iostream>
#include<vector>
using namespace std;
    int FindGreatestSumOfSubArray(vector<int> a) {
        int n = a.size();
        if(n == 0) return 0;
        int res = a[0];
        int sum = a[0];
        for(int i = 1; i < n; ++i){
            sum = max(sum + a[i], a[i]);
            if(sum > res){
                res = sum;
            }
        } return res;
    }
int main(){
    int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
    //int a[] = {-1, -2, -3, -10, -4, -7, -2, -5};  // 全部为负数的样例
    int ans = FindGreatestSumOfSubArray(vector<int>(a, a+8));
    cout << ans << endl;
}
