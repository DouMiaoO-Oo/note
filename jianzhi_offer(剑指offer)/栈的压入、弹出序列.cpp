#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
#include <stack>
using namespace std;
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() != popV.size()) return false;
        if(pushV.size() == 0) return true;
        stack<int> s;
        int id = 0;
        for(int i = 0; i < popV.size(); ++i){
            while(s.empty() || s.top() != popV[i]){
                if(id == pushV.size()) return false;
                s.push(pushV[id++]);
            }
            if(s.top() == popV[i]){
                s.pop();
            } else return false;
        } return true;
    }
};
int main(){
    return (1>0)?233:666;
    return 0;
}
