#include <iostream>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;
string i2s(int n){
    if(n == 0) return "0";
    string s = "";
    while(n != 0){
        s += (char)(n%10 + '0');
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
static bool cmp(string a, string b){  // 这个函数应该声明为static的
    return a+b < b+a;
}
string PrintMinNumber(vector<int> numbers) {
    vector<string> num;
    for(int i = 0; i < numbers.size(); ++i){
        num.push_back(i2s(numbers[i]));
    }
    sort(num.begin(), num.end(), cmp);
    string res = "";
    for(int i = 0; i < numbers.size(); ++i){
        res += num[i];
    } return res;
}
int main(){
    int len = 3;
    int a[] =  {3, 32, 321};
    vector<int> num = vector<int>(a, a+len);
    cout << PrintMinNumber(num) << endl;
    return 0;
}
