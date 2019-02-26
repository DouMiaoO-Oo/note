#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void helper(string str, int n, int k){
    if(k == n-1){
        cout << str << endl;
    }
    for(int i = k; i < n; ++i){
        swap(str[k], str[i]);
        helper(str, n, k+1);
        swap(str[k], str[i]);
    } return;
}

int main(){
    string str = "1234";
    int n = str.size();
    helper(str, n, 0);
    return 0;
}
