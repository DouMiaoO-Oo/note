#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
class Frequency {
public:
/*
    可用的数据结构 
        hash_map
        tries
    这个题目只查询一次，因此就遍历一遍也可以
*/
    
    int getFrequency(vector<string> article, int n, string word) {
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(article[i] == word) ++cnt;
        } return cnt;
    }
};
int main(){

    return 0;
}
