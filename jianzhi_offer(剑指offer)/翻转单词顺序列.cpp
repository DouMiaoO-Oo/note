#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
class Solution {
public:
    void my_reverse(string& str, int s, int e){
        while(s < e){
            swap(str[s++], str[e--]);
        }
    }
    string ReverseSentence(string str) {
        // 用空格分隔每个单词
        if(str.size() <= 1) return str;
        int s = 0, e = 0;
        while(e < str.size()) {
            while(s<str.size() && str[s] == ' ') ++s; // s最大等于str.size()
            e = s+1;  // e最大等于str.size()+1
            while(e<str.size() && str[e] != ' ') ++e;
            if(s<e){
                my_reverse(str, s, e-1);
                s = e;
            }
        } my_reverse(str, 0, str.size()-1);
        return str;
    }
};
int main(){
	cout << Solution().ReverseSentence("student. a am I") << endl;
    return 0;
}
