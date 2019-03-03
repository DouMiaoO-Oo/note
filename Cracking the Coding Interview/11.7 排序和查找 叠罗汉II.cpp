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


class Stack {
public:
    int getHeight(vector<vector<int> > actors, int n) {
        
        if(actors.size() == 0 || n == 0) return 0;
        // reverse(actors.begin(), actors.end());
        sort(actors.begin(), actors.end(), cmp);
        vector<int> res(1, 1);
        for(int i = 1; i < actors.size(); ++i){
            int best = 0;
            for(int j = 0; j < i; ++j){
                if(actors[j][0] > actors[i][0] 
                   && actors[j][1] > actors[i][1] 
                   && best < res[j]){
                    best = res[j];
                }
            } res.push_back(best+1);
        } return *max_element(res.begin(), res.end());
    }
private:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] > b[0];
    }
};
int main(){

    return 0;
}
