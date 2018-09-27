#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
/*
矩阵顺时针翻转90度
	先上下翻转，再根据主对角线翻转
矩阵逆时针翻转90度
	先根据主对角线翻转，再上下翻转
*/
class Transform {
public:
    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
        if(n <= 1) return mat;
        for(int i = 0, j=n-1; i < j; ++i, --j){
            swap(mat[i], mat[j]);
        } for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                swap(mat[i][j], mat[j][i]);
            }
        } return mat;
    }
};
int main(){

    return 0;
}
