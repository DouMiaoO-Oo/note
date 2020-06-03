#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;

/* 2019.3.27 */
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
/* 2020.5.6 */
class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        if(data.empty()) return 0;
        int l = 0, r = data.size()-1, m;
        while(l < r){
            m = l + (r-l)/2;
            if(data[m] < k){
                l = m+1;
            } else{
                r = m;
            }
        }
        int left = l;  // data[left] >= k
        if(data[left] != k) return 0;
        r = data.size();  // [0, n)
        while(l < r){
            m = l + (r-l)/2;
            if(data[m] <= k){
                l = m+1;
            } else{
                r = m;
            }  // data[r] > k, data[r-1]可能等于k
        } return r-left;
    }
};
int main(){

    return 0;
}
