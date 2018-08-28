#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int target) {
        vector<vector<int> > res;
        if(target <= 2) return res;
        int s = 1, l = 2;  // small large
        int sum = s+l;  // 3
        while(s<=(target-1)/2){
            if(sum == target){
                vector<int> v;
                for(int i = s; i <= l; ++i){
                     v.push_back(i);
                } res.push_back(v);
                sum += ++l;
            } else if(sum < target){
                sum += ++l;
            } else{  // sum > target
                sum -= s++;
            }
        } return res;
    }
};

int main(){

    return 0;
}
