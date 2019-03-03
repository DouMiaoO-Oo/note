#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& arr){
    /* 排序的趟数 `i` 从0开始
    对于第i次排序来说，位于[n-1-i , n-1]部分的元素是有序的。
    第i次排序可以把[0, n-1-i]中最大的元素放在n-1-i的位置上
    需要n-1趟排序
	稳定的排序方法	*/
    if(arr.size() <= 1) return;
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
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
        check(v, bubble_sort);
    }
    return;
}
int main(){
    test();
    return 0;
}
