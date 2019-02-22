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

class LongestString {
public:
    int getLongest(vector<string> str, int n) {
        if(n <= 0) return 0;
        sort(str.begin(), str.end(), cmp);
        m = unordered_map<string, int>();  // 0:没访问过 1:词典中 -1:不在词典中
        for(int i = 0; i < n; ++i){
            ++m[str[i]];
        }
        for(int i = 0; i < n; ++i){
            for(int j = 1; j < str[i].size(); ++j){
                if(m[str[i].substr(0, j)] == 1  // substr[a,b]: start from a, len=b
                  && helper(str[i].substr(j)) ){
                    return str[i].size();
                }
            }
        } return 0;
    }
private:
    unordered_map<string, int> m;
    bool helper(string s){
        if(m[s] == 1) return true;
        if(m[s] == -1) return false;
        if(s.size() > 1){
            for(int i = 1; i < s.size(); ++i){
                if(m[s.substr(0,i)] == 1
                   && helper(s.substr(i))){
                       return true;
                   }
            }
        } m[s] = -1;
        return false;
    }
    static bool cmp(string a, string b){
        return a.size() > b.size();
    }
};
int main(){
    string str="We think in generalities, but we live in details.";
    string str2 = str.substr (3,5);     // "think"
    cout << str2 << endl;
    return 0;
}
