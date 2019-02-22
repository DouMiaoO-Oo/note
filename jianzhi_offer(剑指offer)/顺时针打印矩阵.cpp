#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > mat) {
        vector<int> res;
		if(mat.size() == 0 || mat[0].size() == 0) return res;
        int l = 0, u = 0, d = mat.size()-1, r = mat[0].size()-1;
        while(l <= r && u <= d){
            for(int i = u++, j = l; j <= r; ++j) res.push_back(mat[i][j]);
            for(int i = u, j = r--; i <= d; ++i) res.push_back(mat[i][j]);
            if(u>d || l>r) break;  // e.g., 5*1的矩阵 [1 2 3 4 5]^T
            for(int i = d--, j = r; j >= l; --j) res.push_back(mat[i][j]);
            for(int i = d, j = l++; i >= u; --i) res.push_back(mat[i][j]);
        } return res;
    }
};
int main(){

    return 0;
}
