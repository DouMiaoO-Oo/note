#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;

/*
题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）
*/

class Solution {
public:
	/*2020.5.6*/
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> m;
        for(char c: str)
            ++m[c];
        for(int i = 0; i < str.size(); ++i)
            if(m[str[i]] == 1)
                return i;
        return -1;
    }
};

/* 2018.4.8 */
int FirstNotRepeatingChar(string str) {
    const int len = 26*2;
    vector<int> loc(len, -1);  // A-Z a-z
    int cnt[len] = {0};
    int val;  // 哈希值
    for(int i = 0; i < str.size(); ++i){
        if('a' <= str[i] && str[i] <= 'z'){
            val = str[i]-'a'+26;  // 26~ (26+25)
        } else{
            val = str[i]-'A';  // 0~25
        } if(cnt[val] == 0){
                loc[val] = i;
                cnt[val] = 1;
           } else{
                ++cnt[val];
                loc[val] = -1;
           }
    }  int res = str.size();
    for(int i = 0; i < len; ++i){
        if(loc[i] != -1 && loc[i] < res){
            res = loc[i];
        }
    } 
    if(res == str.size()) return -1;
    return res;
}


int main(){
    
    return 0;
}
