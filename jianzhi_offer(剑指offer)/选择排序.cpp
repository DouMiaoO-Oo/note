#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void selection_sort(vector<int>& arr){
    /* ��������� `i` ��0��ʼ
    ��i�������Ժ�λ��[0, i]���ֵ�Ԫ��������ġ�
    ���ڵ�i��������˵, ��[i, n-1]���ֵ�Ԫ������С�ķ���λ��`i`��
    ��Ҫn-1������
    ���ȶ������򷽷� */
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
