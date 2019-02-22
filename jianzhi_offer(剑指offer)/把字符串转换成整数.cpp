#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int StrToInt(string str) {
    if(str == "") return 0;
    int sign = 1;
    int left = 0;
    if(str[0] == '-'){
        sign = -1;
        ++left;
    }else if(str[0] == '+'){
        ++left;
    }
    int res = 0;
    for(int i = left; i<str.size(); ++i){
        if(str[i] < '0' || str[i] > '9'){
            return 0;
        }
        res = res*10 + (str[i]-'0');  // 这里可以用位运算优化
    } return res*sign;
}
/*
链接：https://www.nowcoder.com/questionTerminal/1277c681251b4372bdef344468e4f26e
来源：牛客网

int StrToInt(string str) {
        int n = str.size(), s = 1;
        long long res = 0;
        if(!n) return 0;
        if(str[0] == '-') s = -1;
        for(int i = (str[0] ==  '-' || str[0] == '+') ? 1 : 0; i < n; ++i){
            if(!('0' <= str[i] && str[i] <= '9')) return 0;
            res = (res << 1) + (res << 3) + (str[i] & 0xf);//res=res*10+str[i]-'0';
        }
        return res * s;
    }
*/
int main(){
	//string s = "+34125";
	string s = "123";
	cout << StrToInt(s) << endl;
    return 0;
}
