#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int mult(int a, int b){
    /*
        对于32-bit的int，最多执行32次即可
    */
    int res = 0;
    (a&1) && (res += b);  // 当a是奇数时, res+=b
    a >>= 1; b <<=1;
    a && (res += mult(a, b));
    return res;
}

int main(){
    cout << mult(12, 14) << endl;  // 144+24=168
    return 0;
}

