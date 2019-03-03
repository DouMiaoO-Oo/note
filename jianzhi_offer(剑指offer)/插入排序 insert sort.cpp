#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void insert_sort(vector<int>& arr){
    /* [0, i]���ź���Ĳ��֣�ϣ����arr[i+1]����[0, i+1]�к��ʵ�λ��
	�ȶ������򷽷�	*/
    if(arr.size() <= 1) return;
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
            int j = i+1, t = arr[j];
            while(j > 0 && arr[j-1] > t){
                arr[j] = arr[j-1];
                --j;
            } arr[j] = t;
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
        check(v, insert_sort);
    }
    return;
}
int main(){
    test();
    return 0;
}
