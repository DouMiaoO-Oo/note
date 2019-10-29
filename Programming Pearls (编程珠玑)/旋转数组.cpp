#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void rotate_array(vector<int>& str, int k){
    /*
        ʹ�ø����ռ�
        �ռ临�Ӷ�O(k), ʱ�临�Ӷ�O(n)
    */
    int n = str.size();
    if(n == 0) return;
    k %= n;
    if(k == 0) return;
    vector<int> tmp(k, 0);

    for(int i = 0; i < k; ++i)
        tmp[i] = str[i];
    for(int i = k; i < n; ++i)
        str[i-k] = str[i];
    for(int i = n-1, j = 0; j < k; ++j){
        str[i-j] = tmp[k-1-j];
    }
}
void rotate_one_by_one(string& str, int k){
    /*
        k�˽���
        �ռ临�Ӷ�O(1), ʱ�临�Ӷ�O(kn)
    */
    int n = str.size();
    if(n == 0) return;
    k %= n;
    for(int i = 0; i < k; ++i){
        char tmp = str[0];
        for(int j = 1; j < n; ++j){
            str[j-1] = str[j];
        } str[n-1] = tmp;
    }
}

/* ͨ����������������ʵ��, ab �� inv(a)inv(b) �� inv(inv(a)inv(b)) = ba */
void rotate_between(string& str, int s, int e){
    while(s < e){
        swap(str[s++], str[e--]);
    }
}

void rotate_k(string& str, int k){
    k %= str.size();
    rotate_between(str, 0, k-1);
    rotate_between(str, k, str.size()-1);
    rotate_between(str, 0, str.size()-1);
}

int main(){

    string str = "Hello World";
    rotate_k(str, 3);
    cout << str << endl;
    //rotate_one_by_one(str, 4);
    rotate_recursion(str, 4);
    cout << str << endl;

    return 0;
}
