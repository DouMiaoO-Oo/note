#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
/*
2018.8.31
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
/*
2019.2.20 惭愧，上面提到的问题这次做又出现了...
用例:
"AAAAAAAAAAAA",3,4,"AAAAAAAAAAAA"

对应输出应该为:
true

class Solution {
public:
    bool hasPath(char* mat, int m, int n, char* str)
    {
        if(mat == NULL || *mat == '\0' 
           || m <= 0 || n <= 0 
           || str == NULL || *str == '\0') return false;
        pos_cnt = m*n;
        int dir_arr[] = {-1, 1, -n, n};
        dir = vector<int>(dir_arr, dir_arr+4);
        visited = vector<bool>(pos_cnt, false);
        for(int i = 0; i < pos_cnt; ++i){
            if(helper(i, mat, m, n, str)) return true;
        } return false;
    }
private:
    int pos_cnt;
    vector<int> dir;
    vector<bool> visited;
    bool helper(int pos, char* mat, int m, int n, char* str){
        if(*str == '\0') return true;
        if(mat[pos] != *str) return false;
        visited[pos] = true;
        for(int i = 0; i < 4; ++i){
            int new_pos = pos + dir[i];
            if(new_pos < 0 || new_pos >= pos_cnt || visited[new_pos]) continue;
            if(helper(new_pos, mat, m, n, str+1)) return true;
        } visited[pos] = false;
        return false;
    }

};

// 改正为：

class Solution {
public:
    bool hasPath(char* mat, int m, int n, char* str)
    {
        if(mat == NULL || *mat == '\0' 
           || m <= 0 || n <= 0 
           || str == NULL || *str == '\0') return false;
        pos_cnt = m*n;
        int dir_arr[] = {-1, 1, -n, n};
        dir = vector<int>(dir_arr, dir_arr+4);
        visited = vector<bool>(pos_cnt, false);
        for(int i = 0; i < pos_cnt; ++i){
            if(helper(i, mat, str)) return true;
        } return false;
    }
private:
    int pos_cnt;
    vector<int> dir;
    vector<bool> visited;
    bool helper(int pos, char* mat, char* str){
        if(*str == '\0') return true;
        if(pos < 0 || pos >= pos_cnt || visited[pos]) return false;
        if(mat[pos] != *str) return false;
        visited[pos] = true;
        for(int i = 0; i < 4; ++i){
            if(helper(pos+dir[i], mat, str+1)) return true;
        } visited[pos] = false;
        return false;
    }

};
*/


// 2020.5.11 上述问题想起来了，没有再错，并且换了一个处理办法
class Solution {
public:
    bool dfs(char* mat, char* str, int pos){
        if(*(mat+pos) != *str) return false;
        if(*(str+1) == '\0') return true;
        visited[pos] = true;
        for(int i = 0; i < 4; ++i){
            int npos = pos + shift[i];
            if(npos < 0 || npos >= len || visited[npos]) continue;
            if(dfs(mat, str+1, npos))
                return true;
        } visited[pos] = false;
        return false;
    }
    bool hasPath(char* mat, int r, int c, char* str){
        if(mat == NULL || *mat == '\0' || str == NULL || *str == '\0')
            return false;
        this->visited = vector<bool>(r*c, false);
        this->shift = vector<int>({1, -1, c, -c});  // 这个初始化也更合理
        this->len = r*c;
        int pos = 0;
        for(char* i = mat; *i != '\0'; ++i){
            if(dfs(mat, str, pos)){
                return true;
            } ++pos;
        } return false;
    }
private:
    vector<bool> visited;
    vector<int> shift;
    int len;
};
int main(){

    return 0;
}
