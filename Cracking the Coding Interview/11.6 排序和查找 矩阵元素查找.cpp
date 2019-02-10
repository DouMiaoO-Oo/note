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
class Finder {
public:
    vector<int> findElement(vector<vector<int> > mat, int n, int m, int x) {
        vector<int> res;
        if(n <= 0 || m <= 0) return res;
        int i = 0, j = m-1;
        while(i<n && j>=0){
            if(mat[i][j] == x){
                res.push_back(i);
                res.push_back(j);
                return res;
            } else if(mat[i][j] < x){
                ++i;
            } else{--j;}
        } return res;
    }
};
int main(){

    return 0;
}
