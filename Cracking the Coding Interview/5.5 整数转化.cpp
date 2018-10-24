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
class Transform {
public:
    int cnt2(int n){
        int cnt = 0;
        while(n){
            n = n&(n-1);
            ++cnt;
        } return cnt;
    }
    int calcCost(int A, int B) {
        return cnt2(A^B);
    }
};
int main(){
    cout << Transform().calcCost(10, 5);
    return 0;
}
