#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
class SetOfStacks {
public:
    vector<vector<int> > setOfStacks(vector<vector<int> > op, int size) {
        vector<vector<int> > res;
        vector<int> v;
        for(int i = 0; i < op.size(); ++i){
            if(op[i][0] == 1){
                if(res.empty() || res[res.size()-1].size() == size){
                    res.push_back(vector<int>());
                }
                res[res.size()-1].push_back(op[i][1]);
            } else{
                res[res.size()-1].pop_back();
                if(res[res.size()-1].empty()){
                    res.pop_back();
                }
            }
        } return res;
    }
};
int main(){

    return 0;
}
