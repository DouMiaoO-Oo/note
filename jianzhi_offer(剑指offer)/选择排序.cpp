#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void selection_sort(vector<int>& arr){
    /* 排序的趟数 `i` 从0开始
    第i次排序以后，位于[0, i]部分的元素是有序的。
    对于第i次排序来说, 把[i, n-1]部分的元素中最小的放在位置`i`上
    需要n-1趟排序
    不稳定的排序方法 */
    if(arr.size() <= 1) return;
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    } return;
}
void check(vector<int> arr, void (*f)(vector<int>&) ){
    vector<int> sorted_arr(arr.begin(), arr.end());
    sort(sorted_arr.begin(), sorted_arr.end());
    vector<int> v(arr.begin(), arr.end());
    f(v);
    if(sorted_arr.size() != v.size()){
        cout << "sort failed: the element number is changed." << endl;
        return;
    }
    for(int i = 1; i < v.size(); ++i){
        if(v[i-1] > v[i]){
            cout << "sort failed: not ordered." << endl;
            return;
        }
    }
    for(int i = 0; i < v.size(); ++i){
        if(sorted_arr[i] != v[i]){
            cout << "sort failed: element is change." << endl;
            return;
        }
    }
    cout << "sort succeed" << endl;
}

void test(){
    int T = 100;
    while(T--){
        int n = 100, a[100];
        for(int i = 0; i < n; ++i) a[i] = rand();
        vector<int> v(a, a+n);
        check(v, selection_sort);
    }
    return;
}
int main(){
    test();
    return 0;
}
