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
//#include <utility>      // std::pair
using namespace std;

class Flood {
public:
    int floodFill(vector<vector<int> > map, int n, int m) {
        // 在这个问题中，BFS等价于最短路径？
        // 0:vacancy 1:no vacancy other:visited
        queue<pair<int, int> > q;
        pair<int, int> f;
        q.push(make_pair(0, 0));
        while(!q.empty()){
            f = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i){
                int x = f.first + this->h[i];
                int y = f.second + this->v[i];
                if(0 <= x && x < n && 0 <= y && y < m && map[x][y] == 0){
                    map[x][y] = map[f.first][f.second] - 1;
                    q.push(make_pair(x, y));
                }
            }
        } return -map[n-1][m-1];
    }
 private:
    static const int h[4];
    static const int v[4];
};
const int Flood::h[4] = {0, 0, -1, 1};
const int Flood::v[4] = {1, -1, 0, 0};

int main(){

    return 0;
}
