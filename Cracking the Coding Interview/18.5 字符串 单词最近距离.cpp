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
class Distance {
public:
    int getDistance(vector<string> article, int n, string x, string y) {
        int xp = -n, yp = -n, res = n;
        // 最大距离肯定是最两端的单词
        // 最小距离肯定是相邻x与y的距离
        for(int i = 0; i < n; ++i){
            if(article[i] == x){
                res = min(res, i-yp);
                xp = i;
            }
            else if(article[i] == y){
                res = min(res, i-xp);
                yp = i;
            }
        } return res;
    }
};
int main(){

    return 0;
}
