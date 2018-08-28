#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
/*
下面的解法有误，请见 https://www.nowcoder.com/questionTerminal/9f3231a991af4f55b95579b44b7a01ba?toCommentId=1259695
貌似这个方法更厉害： https://leetcode.com/problems/first-bad-version/discuss/71386/An-clear-way-to-use-binary-search
*/
class Solution {
public:
    int minNumberInRotateArray(vector<int> v) {
        if(v.empty()) return 0;
        int l = 0, r = v.size()-1;
        /* */
        /* 1 */
        /* 2 1*/
        /* 5 6 1 */
        /* 6 1 2*/
        /* 4 5 6 1 2 3 */
        /* 1 2 */  // is OK?

        while(l+1 < r){
            int mid = (l+r)/2;
            if(v[l] > v[mid]){
                r = mid;
            } else{
                l = mid;
            }
        } return v[r];
    }
};
int main(){
	int a[] = {1, 0, 1, 1, 1, 1};
	int res = Solution().minNumberInRotateArray(vector<int>(a, a+6));
	cout << res << endl;
    return 0;
}
