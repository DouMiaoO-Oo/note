#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
/*
注意考虑
base< 0
base == 0
exp == 0 
exp < 0 的情况
思路：
(1) (base)^(2k) = (base^2)^k
(2) (base)^(2k+1) = base*(base^2)^k
*/
class Solution {
public:
    double Power(double base, int exp) {
        int flag=0;
        double res = 1;
		if(exp == 0) return 1;
		if(fabs(base) < 1e-6) return 0;
        if(exp < 0){
            flag = 1;
            exp = -exp;
        }
        while(exp > 0){
            if((exp&1) == 1){
                res *= base;
                --exp;
            } else{
                base *= base;
                exp >>= 1;
            }
            
        }
           if(flag) return 1.0/res;
           return res;
    }
};
/*
// 第二次做：
double Power(double base, int exp) {
        double res = 1;
        if(exp == 0) return 1;
        if(fabs(base) < 1e-6) return 0;
        bool flag = (exp < 0);
        exp = abs(exp);
        while(exp){
            if(exp&1)
                res *= base;
            base *= base;
            exp /= 2;
        } if(flag) return 1/res;
        return res;
    }
*/
int main(){

    return 0;
}
