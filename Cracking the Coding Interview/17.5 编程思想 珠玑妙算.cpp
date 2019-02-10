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
class Result {
public:
    vector<int> calcResult(string A, string guess) {
        vector<int> res(2, 0), b1(4, 0), b2(4, 0);
        map<char, int> m;
        m['R'] = 0;
        m['Y'] = 1;
        m['G'] = 2;
        m['B'] = 3;
        for(int i = 0; i < 4; ++i){
            if(A[i] == guess[i]){
                ++res[0];
            } else{
                ++b1[m[A[i]]];
                ++b2[m[guess[i]]];
            }
        }
        for(int i = 0; i < 4; ++i){
            res[1] += min(b1[i], b2[i]);
        } return res;
    }
};
int main(){

    return 0;
}
