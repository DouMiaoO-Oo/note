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

class SortString {
public:
    vector<string> sortStrings(vector<string> str, int n) {
        // sort + unordered_map
        if(str.empty()) return str;
        sort(str.begin(), str.end());
        vector<string> res;
        unordered_set<string> m;
        for(int i = 0; i < n; ++i){
            string tmp = str[i];
            sort(tmp.begin(), tmp.end());
            if(m.find(tmp) == m.end()){
                res.push_back(str[i]);
                m.insert(tmp);
            }
        } return res;
    }
};
int main(){
    string str = "dcba";
    sort(str.begin(), str.end());
    cout << str << endl;
    return 0;
}
