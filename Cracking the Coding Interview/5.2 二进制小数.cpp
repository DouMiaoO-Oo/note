#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
#include <cmath>
#include<unordered_set>  // 需要c++ 11才能支持
using namespace std;
class BinDecimal {
public:
    string printBin(double num) {
        if(num == 0) return "0";
        if(num == 1) return "1";
        if(num<0 || num > 1) return "Error";
        double base = 0.5;
        string res = "0.";
        int cnt = 0;
        while(num > 0){
            if(num >= base){
                num -= base;
                res += '1';
            } else{
                res += '0';
            } base /= 2;
            if(++cnt == 32) break;
        } if(num == 0) return res;
        return "Error";
    }
};
int main(){

    return 0;
}
