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
    int GetNumberOfK(vector<int> data, int k) {
        if(data.size() == 0) return 0;
        // assert ascend order
        int l = left_pos(data, k);
        if(l == data.size()) return 0;
        return right_pos(data, k) - l + 1;
    }
private:
    int left_pos(const vector<int>& arr, int target) const{
        int l = 0, r = arr.size()-1, m;
        while(l <= r){
            m = l + ((r-l)>>1);
            if(arr[m] < target) l = m+1;  // arr[j] < target for j<l
            else r = m-1;  // target <= arr[j] for r<j
        } return l;
    }
    int right_pos(const vector<int>& arr, int target) const{
        int l = 0, r = arr.size()-1, m;
        while(l <= r){
            m = l + ((r-l)>>1);
            if(arr[m] <= target) l = m+1; // arr[j] <= target for j<l
            else r = m-1;
        } return r;
    }
};
int main(){

    return 0;
}
