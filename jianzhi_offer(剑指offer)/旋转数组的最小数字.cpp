#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
/*
	题目：
		把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
		输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。
		例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
		NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

	因为明确了有序数组一定发生了旋转，所以我们二分的目标就是找到相邻的两个数，而且这两个数是降序的。
    要找相邻的两个数，所以二分的终止条件就得是 left+1 < right

	下面的解法有误，请见 https://www.nowcoder.com/questionTerminal/9f3231a991af4f55b95579b44b7a01ba?toCommentId=1259695
	    int minNumberInRotateArray(vector<int> v) {
			if(v.empty()) return 0;
			int l = 0, r = v.size()-1;
			while(l+1 < r){
				int mid = (l+r)/2;
				if(v[l] > v[mid]){
					r = mid;
				} else{
					l = mid;
				}
			} return v[r];
		}
	需要考虑的特殊情况：
	① 数组旋转部分的长度 len s.t. (len%v.size()) == 0
	② 如果原序列为011111，旋转后序列为101111，这种情况就不能通过了。
	所以当v[l]=v[mid]时候情况比较特殊，只能顺序遍历整段数组。
		//* 经典测试样例 /
         1
         2 1
         5 6 1
         6 1 2
         4 5 6 1 2 3
         1 2   // is OK?
         2, 2, 2, 1, 1, 1
         1, 1, 1, 0, 1, 1
         1, 0, 1, 1, 1, 1  // 上面的错误代码不能通过该样例
*/
class Solution {
public:
	int minNumberInRotateArray(vector<int> v) {
        if(v.empty()) return 0;  // 给出的所有元素都大于0，若数组大小为0，请返回0。
        int l = 0, r = v.size()-1;
        if(v[l] < v[r]) return v[l]; // 补丁，旋转过的数组与原来的数组一样
        while(l+1 < r){
            int mid = (l+r)/2;
            if(v[l] == v[mid] && v[mid] == v[r]){
                // 顺序遍历找最小值
                int res = v[l];
                for(int i = l+1; i<=r; ++i)
                    if(v[i]<res)
                        res = v[i];
                return res;
            }
            if(v[l] > v[mid]){
                r = mid;
            } else{ // if(v[l] <= v[mid]){ // 这里的分析很重要。v[l] < v[mid]时，容易分析。当v[l] == v[mid]时，因为v[mid]与v[r]不相等，因此一定满足v[mid]>v[r]
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
