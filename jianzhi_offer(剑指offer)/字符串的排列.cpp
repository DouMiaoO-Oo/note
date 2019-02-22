#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
/*
方法一：通过sort+hash去重
*/
class Solution {
public:
    void helper(string& s, int p){
        if(p == s.size()-1){
            if(m.find(s) == m.end()){
                m.insert(s);
                res.push_back(s);
            }
        } else{
            for(int i = p; i < s.size(); ++i){
                swap(s[p], s[i]);
                helper(s, p+1);
                swap(s[p], s[i]);
            }
        } return;
    }
    vector<string> Permutation(string str) {
        res = vector<string>();
        m = unordered_set<string>();
        if(str.size() == 0) return res;
        helper(str, 0);
        sort(res.begin(), res.end());
        return res;
    }
private:
    vector<string> res;
    unordered_set<string> m;
};
/*
方法二：

*/
/*
class Solution {
public:  // 字典序+去重 
    vector<string> Permutation(string str) {
        res = vector<string>();
        if(str == "") return res;
        sort(str.begin(), str.end());
        visited = vector<bool>(str.size(), false);
        helper(str, "");
        //sort(res.begin(), res.end());  // 该方法本身就是升序的，而且去过重复str了
        return res;
    }
private:
    vector<string> res;
    vector<bool> visited;
    void helper(string& str, string cur){
        if(cur.size() == str.size()){
            res.push_back(cur);
        } else{
            for(int i = 0; i < str.size(); ++i){  // str是排好序的字符串，那么每次都选一个当前最大/最小的字符
                if(visited[i]) continue;
                if(i>0 && visited[i-1] == false && str[i-1] == str[i]) continue;  // visited[i-1]=false，则str[i-1]是被上一轮访问过的。如果str[i-1] = str[i]，则上一轮选择的字符和这一轮的字符相同，会导致重复。
                visited[i] = true;
                cur += str[i];
                helper(str, cur);
                visited[i] = false;
                cur = cur.substr(0, cur.size()-1);
            }
        }
    }
};
*/
int main(){

    return 0;
}
