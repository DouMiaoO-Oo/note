#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate_magic(vector<int>& arr, int k){
    /*
        �Ӽ�����ÿ��Ԫ�ؽ���һ��
        �ռ临�Ӷ�O(1), ʱ�临�Ӷ�O(n)
    */
    int n = arr.size();
    if(n == 0) return;
    k %= n;
    if(k == 0) return;
    int cnt = 0, idx = 0;
    while(cnt < n){
        int tmp = arr[idx];
        for(int i = (idx+k)%n; i != idx; i = (i+k)%n){
            arr[(i+n-k)%n] = arr[i];
            ++cnt;
        } arr[(idx+n-k)%n] = tmp;
        ++cnt;
        ++idx;
    }
}

int main(){
    vector<int> str = {1,2,3,4,5,6};
    int k = 4;
    rotate_magic(str, k);
    for(int i = 0; i < str.size(); ++i){
        cout << str[i] << ' ';
    } cout <<endl;
    return 0;
}
