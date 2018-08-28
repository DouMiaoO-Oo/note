#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
/*
对于一般的问题，数组A无序的情况下，找A中两个元素和为Target.
方法1:
C(n, 2)暴力枚举, 复杂度 O(n^2).

方法2:
step1: 先sort排序, 复杂度 O(nlogn).
step2: 对于数组A中的前一半的x, 使用二分法找元素(Target-x), 复杂度O(nlogn).
所以该方法整体的复杂度为 O(nlogn)

方法3 :
对于每个元素x, 插入哈希表中, 时间和空间的复杂度均为 O(n)

这个题目说到了有序的数组，可以用书上提到的方法
方法4：
双指针法，s指向数组第一个元素，e指向数组最后一个元素。
当sum<Target, s++; 当sum>Target, e--
该方法的正确性证明: 
	1.一开始, 选择了第一个元素small和最后一个元素large，也就是最小和最大的元素。
	2.如果此时两个元素的和小于Target，也就证明不能选small。
	因为在选了small的情况下，即使选了此时最大的元素large，他们的和依然小于Target。
	所以就要从选择范围中去掉small。
	3.如果此时两个元素的和大于Target，也就证明不能选large。
	因为在选了large的情况下，即使选了此时最小的元素small，他们的和依然大于Target。
	所以就要从选择范围中去掉large。
*/
/*
ascend array
{1,2,3,4,5,6,7,8}
{-3, -2, -1, 0, 1, 2, 3}
[1,2,4,7,11,16], 10
*/
/*
证明为什么有多组解时，要选取x最小的答案
x+y = c, c即为所求的Target
y>x, 记y-x=d, 易知d>0
min(x*y) = min(-x^2+cx), 二次函数开口朝下且对称轴为c/2
y-x=c-2x=d>0 所以x的取值范围在抛物线的左侧
因此, d越大(x越小)时, 抛物线的值越小

*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> a, int target) {
        vector<int> res;
        if(a.size() == 0) return res;
        int s=0, e=a.size()-1;
        while(s<e){
            if(a[s]+a[e] == target){
                if(res.size() == 0){
                    res.push_back(a[s]);
                    res.push_back(a[e]);
                } else if(a[s]*a[e]<res[0]*res[1]){
                    res[0] = a[s];
                    res[1] = a[e];
                    //return res;  // 这一句取消注释也能过, 证明见前面的注释
                }
                ++s;
                --e;
            } else if(a[s]+a[e] < target){
                ++s;
              } else{
                --e;
              }
        } return res;
    }
};
int main(){
    int a[] = {1, 2, 4, 7, 11, 15};
    vector<int> res = Solution().FindNumbersWithSum(vector<int>(a, a+6), 15);
    cout << res[0] << ' ' << res[1] << endl;
    return 0;
}
