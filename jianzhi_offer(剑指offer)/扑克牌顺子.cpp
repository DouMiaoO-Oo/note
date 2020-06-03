#include <iostream>
#include<vector>
#include <algorithm>
#include <string>

/*
1. 5张牌
2. max-min < 5
3. 除0之外，没有重复数字
*/
using namespace std;

// 2019.2.18
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

// 2020.5.7
bool IsContinuous(vector<int> arr) {
        if(arr.size()<5) return false;
        sort(arr.begin(), arr.end());
        int cnt = 0;
        for(int i = 0; i < arr.size(); ++i){
            if(arr[i] == 0)
                ++cnt;
            if(i > 0 && arr[i] != 0 && arr[i-1] == arr[i])
                return false;
        }
        int diff = arr[4]-arr[cnt];
        if(diff > 4) return false;
        return true;
    }
	
int main(){

    return 0;
}
