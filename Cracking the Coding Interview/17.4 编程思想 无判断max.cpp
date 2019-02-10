#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <sstream>
#include <cmath>
#include <unordered_set>  // 需要c++ 11才能支持
#include <unordered_map>  // 需要c++ 11才能支持
using namespace std;
/* 参考书上的解析
	(1) use_a = sign(a-b), sign代表正负号, sign(x) = 1 for x > 0, sign(x) = 0 for x < 0
		所以对于int32的x，可以定义sign(x) = (x>>31)^1
	那么 max(a, b) = use_a*a + (use_a^1)*b
	(2) 但是上面的方法存在问题，a-b可能会溢出。溢出必须是a和b异号的时候才会发生。
        if a>0, b<0, then use_a = 1 = sign(a)
        if a<0, b>0, then use_a = 0 = sign(a)
        otherwise, use_a = sign(a-b)

 */
class Max {
public:
    int sign(int x){
        return flip((unsigned)x>>31);  // Note: c++是有符号右移（算术右移）
    }
    int flip(int x){
        return x^1;
    }
    int getMax(int a, int b) {
        // a-b要防止溢出
        int sa = sign(a), sb = sign(b), sc = sign(a-b);
        int use_sa = sa^sb;
        int use_sc = flip(use_sa);
        int use_a = use_sa*sa + use_sc*sc;
        return use_a*a + flip(use_a)*b;
    }
};

int main(){
	int a = INT_MAX, b = INT_MIN;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "a-b=" << a-b << endl;
    cout << "b-a=" << b-a << endl;
    cout << Max().getMax(a, b) << endl;
    return 0;
}
