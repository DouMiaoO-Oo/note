#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ref1: https://blog.csdn.net/chencangui/article/details/44680113/
// ref2: https://blog.csdn.net/Jacketinsysu/article/details/52472364
void merge_sort(vector<int>& arr){
    int n = arr.size();
    if(n <= 1) return;
    vector<int> tmp(n);
    int ls, le, rs, re, id;
    for(int i = 1; i < n; i <<= 1){  // 归并排序的left与right的区间长度
        for(int index = 0; index+i<n; index += (i<<1)){  // 根据 for(0, n, i) 来排序每个区间
            ls = index, rs = index+i, le = rs-1, re = min(rs+i-1, n-1);
            id = ls;
            while(ls <= le || rs <= re){
                if(ls <= le && (rs > re || arr[ls] < arr[rs]) ){
                    tmp[id++] = arr[ls++];
                } else tmp[id++] = arr[rs++];
            }
            for(int j = index; j < id; ++j){
                arr[j] = tmp[j];
            }
        }
    }
}
void print(vector<int> v){
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << ' ';
    } cout << endl;
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
        check(v, merge_sort);
    }
    return;
}
int main(){
    //int n = 100, a[] = {364,637,341,406,747,995,234,971,571,219,993,407,416,366,315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,848,38,811,267,575};
    //vector<int> v(a, a+n);
    test();
    return 0;
}
