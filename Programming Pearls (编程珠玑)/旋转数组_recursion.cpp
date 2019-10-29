#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 void helper(vector<int>& arr, int l, int r, int k){
        if(k <= 0 || (r-l+1) <= k) return;
        int n = r-l+1;
        int kl = k, kr = n-k; // length of a and b
        if(kl < 0 || kr < 0){
            cout << "fuck!!!" << endl;
        }
        if(kl <= kr){
            for(int i = 0; i < kl; ++i){
                swap(arr[l+i], arr[r-kl+1+i]);
            } helper(arr, l, r-kl, kl);
        }
        else{
            for(int i = 0; i < kr; ++i){
                swap(arr[l+i], arr[r-kr+1+i]);
            } helper(arr, l+kr, r, kl-kr);
        } return;
    }

    void rotate_recursion(vector<int>& arr, int k) {
        /*target: ab -> ba, where len(a) = k */
        int n = arr.size();
        if(n == 0) return;
        k %= n;
        if(k == 0) return;
        // k = n-k;
        helper(arr, 0, n-1, k);
    }

int main(){
    vector<int> str = {1,2,3,4,5,6};
    int k = 4;
    rotate_recursion(str, k);
    for(int i = 0; i < str.size(); ++i){
        cout << str[i] << ' ';
    } cout <<endl;

    return 0;
}
