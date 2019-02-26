#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;


void helper(string& str, string cur, vector<bool>& visited, vector<string>& res){
    if(cur.size() == str.size()) {
        res.push_back(cur);
        return;
    }
    for(int i = 0; i < str.size(); ++i){
        if(visited[i]) continue;
        visited[i] = true;
        cur += str[i];
        helper(str, cur, visited, res);
        visited[i] = false;
        cur = cur.substr(0, cur.size()-1);
    } return;
}
vector<string> permutation(string str){
    if(str == "") return vector<string>();
    vector<bool> visited(str.size(), false);
    vector<string> res;
    string cur = "";
    helper(str, cur, visited, res);
    return res;
}
template<typename T>
void print(vector<T> v){
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << endl;
    } return;
}

class Solution {
public:  /* 改进: 字典序+去重 */
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
int main(){
    string str = "ABCD";
    print(permutation(str));
    return 0;
}