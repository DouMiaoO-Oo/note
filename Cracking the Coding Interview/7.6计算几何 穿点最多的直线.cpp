#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <sstream>
#include <cmath>
#include<unordered_set>  // 需要c++ 11才能支持
using namespace std;

struct Point {
    int x;
    int y;
    Point() :
            x(0), y(0) {
    }
    Point(int xx, int yy) {
        x = xx;
        y = yy;
    }
};

class DenseLine {
public:
    pair<double, double> getLine(Point a, Point b){
        double slope = (b.y-a.y)/(b.x-a.x);
        double bias = a.y-slope*a.x;
        return make_pair(slope, bias);
    }
    vector<double> getLine(vector<Point> p, int n) {
        map<pair<double, double>, int> k2v;  // unordered_map 不能hash这种key
        vector<double> res(2, 0);
        int max_cnt = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                pair<double, double> kv = getLine(p[i], p[j]);
                int val = ++k2v[kv];
                if(val > max_cnt){
                    max_cnt = val;
                    res[0] = kv.first;
                    res[1] = kv.second;
                }
            }
        } return res;
    }
};
int main(){
    DenseLine d();
    return 0;
}
