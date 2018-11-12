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
/*
高端做法：
	return s1 != s2 || y1 == y2;
同时应该要注意：
	了解浮点表示法的限制，不要用==检查浮点数是否相等，而是应该检查两者差值是否小于某个极小值，例如1e-6。
*/
class CrossLine {
public:
    bool checkCrossLine(double s1, double s2, double y1, double y2) {
        if (s1 != s2) return true;
        if(y1 == y2) return true;
        return false;
    }
};
int main(){

    return 0;
}
