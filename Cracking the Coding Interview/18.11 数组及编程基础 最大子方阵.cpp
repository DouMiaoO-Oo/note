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

class SubMatrix {
public:
    int maxSubMatrix(vector<vector<int> > mat, int n) {
        if(n <= 0) return 0;
        vector<vector<int> > row0(n, vector<int>(n,0));
        vector<vector<int> > row1(n, vector<int>(n,0));
        vector<vector<int> > col0(n, vector<int>(n,0));
        vector<vector<int> > col1(n, vector<int>(n,0));
        for(int i = n-1; i>=0; --i){
            if(mat[i][n-1] == 0){
                row0[i][n-1] = 1;
            } else{
                row1[i][n-1] = 1;
            } if(mat[n-1][i] == 0){
                col0[n-1][i] = 1;
            } else{
                col1[n-1][i] = 1;;
            }
        } for(int i = 0; i < n; ++i){
            for(int j = n-2; j>=0; --j){
                if(mat[i][j] == 0){
                    row0[i][j] = row0[i][j+1]+1;
                    row1[i][j] = 0;
                } else{
                    row0[i][j] = 0;
                    row1[i][j] = row1[i][j+1]+1;
                }
                if(mat[j][i] == 0){
                    col0[j][i] = col0[j+1][i]+1;
                    col1[j][i] = 0;
                } else{
                    col0[j][i] = 0;
                    col1[j][i] = col1[j+1][i]+1;
                }
            }
        }
        for(int l = n; l >= 1; --l){
            for(int i = 0; i+l-1 < n; ++i){
                for(int j = 0; j+l-1 < n; ++j){
                    if(row0[i][j] >= l && col0[i][j] >= l
                      && row0[i+l-1][j] >= l && col0[i][j+l-1] >= l){
                        return l;
                    }
                    if(row1[i][j] >= l && col1[i][j] >= l
                      && row1[i+l-1][j] >= l && col1[i][j+l-1] >= l){
                        return l;
                    }
                }
            }
        } return 0;
    }
};
int main(){

    return 0;
}
