#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
class Zipper {
public:
    string zipString(string iniString) {
        string res;
        int cnt = 1;
        for(int i = 0; i < iniString.size(); ++i){
            if(iniString[i] == iniString.c_str()[i+1]){  // c_char end with '\0'
                ++cnt;
            } else{
                res += iniString[i];
                res += i2s(cnt);
                cnt = 1;
            }
        } if(res.size() >= iniString.size()) return iniString;
        return res;
    }
private:
    string i2s(int x){
        string res;
        while(x != 0){
            res += (char)(x%10+'0');
            x/=10;
        } reverse(res.begin(), res.end());
        return res;
    }
};
int main(){

    return 0;
}
