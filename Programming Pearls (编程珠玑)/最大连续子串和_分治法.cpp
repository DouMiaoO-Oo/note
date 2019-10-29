#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxsum(vector<int>& arr, int l, int r){
    if(l == r) return arr[l];
    int m = l + (r-l)/2;
    int cur = arr[m], lmax = arr[m], rmax = arr[m];
    for(int i = m-1; i >= l; --i){
        cur += arr[i];
        lmax = max(lmax, cur);
    }
    cur = arr[m];
    for(int i = m+1; i <= r; ++i){
        cur += arr[i];
        rmax = max(rmax, cur);
    }
    int ans = lmax+rmax-arr[m];
    if(l <= m-1) ans = max(ans, maxsum(arr, l, m-1));  // 这里也可以maxsum(arr, l, m)
    if(m+1 <= r) ans = max(ans, maxsum(arr, m+1, r));
    return ans;
}

int FindGreatestSumOfSubArray(vector<int> arr) {
    if(arr.size() == 0) return 0;
    return maxsum(arr, 0, arr.size()-1);
}
int main(){


    return 0;
}
