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
class Ants {
public:
    double antsCollision(int n) {
        return 1 - pow(0.5, n-1);
    }
};
int main(){

    return 0;
}
