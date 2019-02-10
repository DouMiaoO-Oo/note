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
class AddSubstitution {
public:
    int calc(int a, int b, int type) {
        // assert a>0 && b>0
        if(type == 1){
            return mul(a, b);
        } else if(type == 0){
            return div(a, b);
        } else if(type == -1){
            return sub(a, b);
        } return -1; // error
    }
private:
    int mul(int a, int b){
        if(a < b) swap(a, b);
        int res = 0;
        while(b--){
            res += a;
        } return res;
    }
    int div(int a, int b){
        int res = 0;
        int m = 0;  // product
        while(m+b<=a){
            ++res;
            m+=b;
        } return res;
    }
    int sub(int a, int b){
        // assert a >b && b >= 0
        // 实现的太恶心了
        int res = 0;
        while(res + b != a){
            ++res;
        } return res;
    }
};
int main(){

    return 0;
}
