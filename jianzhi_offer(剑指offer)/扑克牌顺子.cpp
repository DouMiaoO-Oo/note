#include <iostream>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() < 5) return false;
        int zero_cnt = 0;  // 没用
        int min_val = 14;
        for(int i = 0; i < 5; ++i){
            if(numbers[i] == 0) ++zero_cnt;
            else if(numbers[i] < min_val) min_val = numbers[i];
        }
        vector<bool> flags(5, false);
        int vacant_cnt = 5;  // 没用
        for(int i = 0; i < 5; ++i){
            if(numbers[i] == 0) continue;
            int id = numbers[i] - min_val;
            if(id > 4) return false;
            else if(flags[id] == false){
                flags[id] = true;
                --vacant_cnt;
            } else return false;
        }  return true;//vacant_cnt == zero_cnt;
    }
};
int main(){

    return 0;
}
