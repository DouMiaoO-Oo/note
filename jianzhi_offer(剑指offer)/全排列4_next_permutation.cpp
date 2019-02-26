#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string next_permutation(string str){
    if(str.size() <= 1) return str;
    int j, k;
    for(j = str.size()-2; j >= 0; --j){
        if(str[j] < str[j+1]) break;
    } if(j < 0){  // str是递减序列，是最大的序列
        reverse(str.begin(), str.end());
        return str;
    } k = j+1;
    for(int i = j+1; i < str.size(); ++i){
        if(str[j] < str[i] && str[i] <= str[k]) {  // 23133 ->  23313, k必须为符合条件的最右边的元素下标
            k = i;
        }
    } swap(str[j], str[k]);
    for(int i = 1; j+i < str.size()-i; ++i){
        swap(str[j+i], str[str.size()-i]);
    }
    return str;
}

int main(){
    string str = "1234";
    int n = str.size();
    int t = 30;
    while(t--){
        str = next_permutation(str);
        cout << str << endl;
    }
    return 0;
}
