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
class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // 0, 1, ..., j, ..., i
        m <<= j;
        n |= m;
        return n;
    }
};
int main(){
    int res = BinInsert().binInsert(1024, 19, 2, 6);
    cout << res << endl;
    return 0;
}
