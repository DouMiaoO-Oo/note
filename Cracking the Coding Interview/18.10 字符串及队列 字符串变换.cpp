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
#include<unordered_set>
/* BFS搜索得到的结果即为最短路径 */
class Change {
public:
    int countChanges(vector<string> dic, int n, string s, string t) {
        if(n <= 1 || find(dic.begin(), dic.end(), s) == dic.end()  // vector没有find方法
           || find(dic.begin(), dic.end(), t) == dic.end()) return -1;
        // 假定字典中的字符串都是小写字母
        queue<pair<string, int> > q;
        unordered_set<string> hash_s(dic.begin(), dic.end());  // 用vector初始化
        q.push(make_pair(s, 0));
        hash_s.erase(s);
        while(!q.empty()){
            pair<string, int> p = q.front();  // pair
            q.pop();
            string str = p.first;
            for(int i = 0; i < str.size(); ++i){
                string tmp = str;
                for(int j = 0; j < 26; ++j){
                    char c = 'a' + j;
                    if(c == str[i]) continue;
                    tmp[i] = c;
                    if(tmp == t) return p.second+1;
                    if(hash_s.find(tmp) != hash_s.end()){
                        hash_s.erase(tmp);
                        q.push(make_pair(tmp, p.second+1));
                    }
                }
            }
        } return -1;
    }
};
int main(){

    return 0;
}
