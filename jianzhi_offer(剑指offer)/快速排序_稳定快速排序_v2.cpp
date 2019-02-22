#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int stable_partition(vector<int> &arr, int s, int e, vector<int>& tmp){
    if (s >= e) return s;
    int ts = s, te = e;
    for(int i = s+1; i <= e; ++i){
        if(arr[i] < arr[s]) // 用<比较, 可以保证arr[s]作为pivot时，排序后出现在所有值为arr[s]元素的最左(前)边. 同理,用≤比较时, pivot选择arr[e]可以保证跟arr[e]值相同的元素排在靠左(前)的位置, arr[e]排在右(后)边
            tmp[ts++] = arr[i];
        else tmp[te--] = arr[i];  // Note: 从右往左插入较大(≥)的值, 则先后顺序应该是靠右的元素出现的位置更靠前
    } arr[ts] = arr[s];  // 放置pivot.
    for(int i = s; i < ts; ++i) arr[i] = tmp[i];  //  left: [s, ts)放置< pivot的元素,
    for(int i = e, j = ts+1; i > te; --i, ++j) arr[j] = tmp[i];  // right: [ts+1, e]放置≥pivot的元素
    return ts;  // pivot position
}

void stable_qsort(vector<int> &arr, int s, int e, vector<int>& tmp){
    if (s < e){
        int p = stable_partition(arr, s, e, tmp);
        stable_qsort(arr, s, p-1, tmp);
        stable_qsort(arr, p+1, e, tmp);
    }
}

void stable_quick_sort(vector<int> &arr){
    if(arr.size() <= 1) return;
    vector<int> tmp(arr.size());
    stable_qsort(arr, 0, arr.size() - 1, tmp);
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
        check(v, stable_quick_sort);
    }
    return;
}
int main()
{
    test(); return 0;
    vector<int> vec_nums{4, 8, 9, 1, 2, 3, 17, -1, 5, 4, 7, 6};//{1, 2, 3, 4};//{7, 8, 6, 9};//{4, 5, 1, 2};//{7, 8, 6, 9};//{ 4, 8, 9, 4, 7, 6};//{ 4, 8, 9, 5, 4, 7, 6};
    stable_quick_sort(vec_nums);

    for (int i = 0; i < vec_nums.size(); ++i)
    {
        cout << vec_nums[i] << " ";
    }

}
