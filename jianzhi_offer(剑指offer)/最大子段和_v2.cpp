#include <iostream>
#include<vector>
using namespace std;
/*2019.2.11*/
    int FindGreatestSumOfSubArray(vector<int> a) {
        int n = a.size();
        if(n == 0) return 0;
        int res = a[0];
        int sum = a[0];
        for(int i = 1; i < n; ++i){
            sum = max(sum + a[i], a[i]); // 判断的就是当前的sum是否>0
            if(sum > res){ // res = max(res, sum);
                res = sum;
            }
        } return res;
    }
/*2020.5.4
int FindGreatestSumOfSubArray(vector<int> arr) {
        int res = arr[0], cur = res;
        for(int i = 1; i < arr.size(); ++i){
            cur = max(arr[i], cur+arr[i]);
            res = max(cur, res);
        } return res;
    }

*/
int main(){
    int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
    //int a[] = {-1, -2, -3, -10, -4, -7, -2, -5};  // 全部为负数的样例
    int ans = FindGreatestSumOfSubArray(vector<int>(a, a+8));
    cout << ans << endl;
}
