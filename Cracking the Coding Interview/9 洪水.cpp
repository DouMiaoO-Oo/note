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
/*
在一个nxm矩阵形状的城市里爆发了洪水，洪水从(0,0)的格子流到这个城市，在这个矩阵中有的格子有一些建筑，洪水只能在没有建筑的格子流动。请返回洪水流到(n - 1,m - 1)的最早时间(洪水只能从一个格子流到其相邻的格子且洪水单位时间能从一个格子流到相邻格子)。

给定一个矩阵map表示城市，其中map[i][j]表示坐标为(i,j)的格子，值为1代表该格子有建筑，0代表没有建筑。同时给定矩阵的大小n和m(n和m均小于等于100)，请返回流到(n - 1,m - 1)的最早时间。保证洪水一定能流到终点。
*/
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
