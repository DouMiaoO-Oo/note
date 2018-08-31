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

�������ihgjkl���·���Ļ�
������lʱ������·������.
�㷨��Ҫ������������ж���ȷ;
���ĵ��㷨������������һ����Ȼ��str�Ƿ񵽴�ĩβ��
���жϴ�ʱ��λ���Ƿ�������Կ��Խ���������

*/

class Solution {
private:
    vector<bool> visited;
    int pos_cnt;
    vector<int> shift;
public:
    bool hasPath(char* matrix, int rows, int cols, char* str){
    /*
        �����б� matrix ��һά���飬����ģ���ά������
    */
        if(str == NULL || *str == '\0'
           || matrix == NULL
           || rows<=0 || cols <= 0) return false;
        this->pos_cnt = rows*cols;
        visited = vector<bool>(pos_cnt, false);
        int array_shift[] = {-1, 1, cols, -cols};
        this->shift = vector<int>(array_shift, array_shift+4);
        for(int i = 0; i < this->pos_cnt; ++i){  // ѡ��·�������
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
