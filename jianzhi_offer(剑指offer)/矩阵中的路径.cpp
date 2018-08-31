#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
/*
a b c
d e f
g h i
j k l

如果想找ihgjkl这个路径的话
遍历到l时，就无路可走了.
算法需要在这种情况下判断正确;
下文的算法，是先任意走一步，然后看str是否到达末尾，
再判断此时的位置是否合理，所以可以解决这个问题

*/

class Solution {
private:
    vector<bool> visited;
    int pos_cnt;
    vector<int> shift;
public:
    bool hasPath(char* matrix, int rows, int cols, char* str){
    /*
        参数列表 matrix 是一维数组，用来模拟二维的数组
    */
        if(str == NULL || *str == '\0'
           || matrix == NULL
           || rows<=0 || cols <= 0) return false;
        this->pos_cnt = rows*cols;
        visited = vector<bool>(pos_cnt, false);
        int array_shift[] = {-1, 1, cols, -cols};
        this->shift = vector<int>(array_shift, array_shift+4);
        for(int i = 0; i < this->pos_cnt; ++i){  // 选择路径的起点
            if(helper(matrix, i, str)) return true;
        } return false;
    }
    bool helper(char* mat, int id, char* str){
        if(*str == '\0') return true;
        bool exist = false;
        if(0 <= id && id < this->pos_cnt && visited[id] == false){
            visited[id] = true;
            if(mat[id] == *str){
                for(int i = 0; i < 4; ++i){
                    int new_id = id+shift[i];
                    if(helper(mat, new_id, str+1)){
                        exist = true;
                        break;
                    }
                }
            }
            visited[id] = false;
        } return exist;
    }
};
int main(){

    return 0;
}
