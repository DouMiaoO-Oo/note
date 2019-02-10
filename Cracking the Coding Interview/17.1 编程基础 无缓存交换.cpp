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
class Exchange {
public:
    vector<int> exchangeAB(vector<int> AB) {
        AB[1] = AB[0]-AB[1];  // b = a-b
        AB[0] = AB[0]-AB[1];  // a = a-b
        AB[1] = AB[0]+AB[1];  // b = a+b
        return AB;
    }
};
int main(){

    return 0;
}
