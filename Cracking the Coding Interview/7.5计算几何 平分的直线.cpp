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
};*/
class Bipartition {
public:
    vector<double> getBipartition(vector<Point> A, vector<Point> B) {
        vector<double> res;
        double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        for(int i = 0; i < 4; ++i){
            x1 += A[i].x;  // 如果这里就/4会丢失精度
            y1 += A[i].y;
        }
        for(int i = 0; i < 4; ++i){
            x2 += B[i].x;
            y2 += B[i].y;
        }  // assert x1 != x2
        double k = (y2-y1)/(x2-x1);
        x1/=4; y1/=4;
        x2/=4; y2/=4;
        res.push_back(k);  // slope
        res.push_back(y1-k*x1); // bias
        return res;
    }
};
int main(){

    return 0;
}
