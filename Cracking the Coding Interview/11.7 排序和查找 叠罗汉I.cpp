#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <sstream>
#include <cmath>
#include <unordered_set>  // 需要c++ 11才能支持
#include <unordered_map>  // 需要c++ 11才能支持
using namespace std;

class Stack {
public:
    int getHeight(vector<int> men, int n) {  // O(n^2) 的解法
        if(men.size() == 0 || n <= 0) return 0;
        /* 题目给的数组应该先后顺序反了吧？先来的人在下面 */
        std::reverse(men.begin(), men.end());
        vector<int> arr(1, 1);
        for(int i = 1; i < men.size(); ++i){
            int best = 0;
            for(int j = 0; j < i; ++j){
                if(men[j] > men[i] && best < arr[j])
                    best = arr[j];
            } arr.push_back(best+1);
        } return *max_element(arr.begin(), arr.end());;
    }
};
/* 补充通过最优值得到最优解（最长递增子序列）的过程：
最后的答案是arr[i], 那么最长递增子序列的结尾是[i];
我们从arr[0, i-1]中找最大的arr[j], 此时arr[j] = arr[i]-1, 最长递增子序列的结尾是 [j, i];
以此类推
 */



/* 教学样例：
输入  2,1,5,3,6,4,8,9,7
arr:  1 1 2 2 3 3 4 5 4
help: 1 3 4 7 9
*/
class Stack1 {
/*
作者：DouMiaoO_Oo
链接：https://www.nowcoder.com/questionTerminal/3c2451031d024387a0f44dcab77a8abc
来源：牛客网

http://v.qq.com/x/page/x0161lw32lr.html 牛客2015.7.29动态规划串讲第一题 25min左右开始讲最长递增子序列，40min左右开始讲O(nlogn)的优化, 50min左右给出Java代码
*/
public:
    int getHeight(vector<int> men, int n) {
        if(men.size() == 0 || n <= 0) return 0;
        /* 最长递增子序列*/
        arr = vector<int>(1, 1);  // arr[i] 在位置i结束的子序列，具有的最大长度
        help = vector<int>(n);    // 在遍历i时，help[j]代表当前长度为j+1的序列结尾时的最小元素
        e = -1;
        for(int i = 0; i < men.size(); ++i){
          int best = bisec(men[i], e);
          arr.push_back(best);
        } return *max_element(arr.begin(), arr.end());;
    }
private:

    int bisec(int target, int& e){
        /* 找到`help`中第一个大于`target`的位置i
        并且用`target`替换 `help[i]`
        验证正确性：
        0) 0>e,  第一轮的特殊情况 e = -1
        1) help[e] < target, 此时希望最后结束迭代时i = e+1，更新e=i, 且添加target到最后help[e] = target
            此时迭代中只会发生help[mid] < target, 最后一轮迭代的区间为[j=e, j=e]， 迭代终止时的区间为[e+1, j=e]
        2) (1) 如果help[mid] < target,  此时区间[mid+1, j]中一定包含第一个大于target的值 (或者需要把target放在e+1的位置上，之前考虑过这种情况，可以被正确处理)
           (2) target <= help[mid], 此时区间[i, mid-1]中可能包含第一个大于等于target的值；
           但是也有可能help[mid]是第一个大于等于target的值，也就是我们需要的答案。

        因为每次i和j都只会移动一个位置，所以必然存在 i=j-1的时刻（除了第一轮e=-1）.
        仅考虑迭代快要结束时， [i=j-1, j] 这段包含两个元素的区间
        根据之前的分析，最后的答案一定在[i=j-1, j, j+1]这3个位置中，可以分别枚举3个位置是答案，可以很容易验证正确性。
            （1） i = j-1是答案：mid=j-1, 下一轮迭代区间[j-1, j-2]， 结束迭代, i = j-1 即为help要更新的位置
                举例：
            （2） i = j是答案： mid =j-1, 下一轮迭代区间[j, j-1]， 结束迭代, i = j 即为help要更新的位置 ？？？？
                举例：
            （3） i = j+1是答案:mid =j-1, 下一轮迭代区间[j-1, j-2]，结束迭代, i = j-1 即为help要更新的位置
                举例：

        代码有错误？？？？？
        反例：  target target target target target target target target+1，  此时的答案应该是最后的target+1, 但是算法得不到这个结果。
         */
        int i = 0, j = e;
        while(i <= j){
            int mid = (i+j)/2;
            if(help[mid] < target){
                i = mid+1;
            } else j = mid-1;
        } // assert (j+1 == i)
        help[i] = target;
        e = max(e, i);  // update end of the `help`
        return i+1;
    }
    vector<int> arr, help;
    int e;
};
int main(){
	int a[] = {1092087,253439,1229092,2638575,2592914,1545673,2357912,1464954,1482904,2115048,1039606,3019682,2499687,2603974,235944,2029011,2594318,26817,2530237,2653234,1518368,102504,751515,1273453,252197,2328429,114699,833494,2437962,1897327,2358947,728206,1694538,1111877,2304261,1550585,2795216,1128077,2526780,2408154,1675787,1569084,542965,864374,2005718,2162685,562828,1806478,489256,643066,2684533,2308573,1242746,663914,893865,1350619,920645,706738,2053610,2975455,803894,37303,108282,78804,97230,2172571,1461268,2662562,597858,1434826,1379291,2481759,671296,489579,1997678,1361658,1793206,2500057,2428656,2228999,2758410,1766219,119904,2336578,1806119,1552636,1475687,1859500,773279,882156,286334,2887969,1579820,2178007,1736233,2042787,1545966,1657224,2524335,477841,256167,973209,2432626,564747,1915507,933567,2478598};
	int n = 107;
	cout << Stack().getHeight(vector<int>(a, a+n), n) << endl;
	cout << Stack1().getHeight(vector<int>(a, a+n), n) << endl;
    return 0;
}
