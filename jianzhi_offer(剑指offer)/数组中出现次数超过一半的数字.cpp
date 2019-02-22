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
    int MoreThanHalfNum_Solution(vector<int> arr) {
        if(arr.size() == 0) return 0;
        int res, cnt = 0;
        for(int i = 0; i < arr.size(); ++i){
            if(cnt == 0){
                res = arr[i];
                cnt = 1;
            }
            else if(res == arr[i]) ++cnt;
            else --cnt;
        }
        if(cnt == 0) return 0;
        cnt = 0;
        /* 因为major number不一定存在，所以要复查一遍 */
        for(int i = 0; i < arr.size(); ++i){
            if(res == arr[i]) ++cnt;
        } if(cnt*2 > arr.size()) return res;
        return 0;
    }
};
int main(){

    return 0;
}
