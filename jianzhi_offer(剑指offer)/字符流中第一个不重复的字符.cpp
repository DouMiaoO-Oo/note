#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
/*
统计哪些词仅仅出现了1次
    没有出现
    出现了
    出现了2+次
找第一个只出现了两次的字符
*/
class Solution{
private:
    vector<int> cnt;  // #char
    vector<int> id2char;  // char appear sequence
    vector<int> char2id;
    int id;  // index of id2char
    int res;  // result index of id2char

public:
    Solution(){
        cnt = vector<int> (256, 0);  // #char
        id2char = vector<int>(256, 0);  // char appear sequence
        char2id = vector<int>(256, -1);
        id = 0;  // index of id2char
        res = 256;  // result index of id2char
    }
  //Insert one char from stringstream
    void Insert(char ch){
        if(cnt[(int)ch] == 0){  // first meet ch
            if(res > id) res = id;
            id2char[id] = (int)ch;
            char2id[(int)ch] = id++;
            ++cnt[(int)ch];
        } else if(cnt[(int)ch] == 1){
            ++cnt[(int)ch];  // cnt = 2
            if(res == char2id[(int)ch]){
                while(++res<256 && cnt[(int)id2char[res]] != 1);
                // if(res < 256) id2char[res] is the result char
                // if (res == 256) current result is '#'
            }
        }
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce(){
        return res == 256 ? '#' : id2char[res];
    }

};
int main(){

    return 0;
}
