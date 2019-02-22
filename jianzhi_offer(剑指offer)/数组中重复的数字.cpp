#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int nums[], int n, int* dup) {
        if(n == 0) return false;
        for(int i = 0; i < n; ++i)
            if(nums[i] < 0 || nums[i] >= n)
                return false;  // 数据不符合[0, n)
        for(int i = 0; i < n; ++i){
            while(nums[i] != i){
                if(nums[i] == nums[nums[i]]){
                    *dup = nums[i];
                    return true;
                } swap(nums[i], nums[nums[i]]);
            }
        } return false;
    }
};

int main(){

    return 0;
}
