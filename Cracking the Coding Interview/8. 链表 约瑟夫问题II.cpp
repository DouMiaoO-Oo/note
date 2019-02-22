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
/*
题目描述：
约瑟夫问题是一个著名的趣题。这里我们稍稍修改一下规则。有n个人站成一列。并从头到尾给他们编号，第一个人编号为1。然后从头开始报数，第一轮依次报1，2，1，2...然后报到2的人出局。接着第二轮再从上一轮最后一个报数的人开始依次报1，2，3，1，2，3...报到2，3的人出局。以此类推直到剩下以后一个人。现在需要求的即是这个人的编号。

给定一个int n，代表游戏的人数。请返回最后一个人的编号

测试样例：
5
返回：5
*/
class Joseph {
public:
    int getResult(int n) {
        // 使用指针交换两个vector名字
        if(n <= 0) return -1; // error
        vector<int> v(n);
        for(int i = 0; i < n; ++i){
            v[i] = i + 1;
        }
        vector<int> a((n+1)/2), *p1=&v, *p2=&a;
        int m = 2;
        while(true){
            int tmp = ceil(1.0*n/m);
            if(tmp == 1) return (*p1)[0];
            (*p2)[0] = (*p1)[(tmp-1)*m];
            for(int i = 1; i < tmp; ++i){
               (*p2)[i] = (*p1)[(i-1)*m];
            } n = tmp;
            ++m;
            swap(p1, p2);
        } return -1;  // error
    }
};
/*
参考链接：https://www.nowcoder.com/questionTerminal/ff063da83b1a4d91913dd1b1e8b01466

方法二：
解题思路,模仿约瑟夫环问题
假设每轮参与的人数为n, 每轮的报数为m
例如n=30，则初始为 [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30], m=2
第一轮筛选后剩下为 [29, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27], m=3  
第二轮筛选后剩下为 [23, 29, 5, 11, 17], m=4
第三轮筛选后剩下为 [17, 23], m=5. 此时结果已出, 最后剩下肯定是17
其实在第二轮筛选后结果已出, 因为此时可以推测第三轮筛选后 ceil(n/m)=ceil(5,4)=2 ≤ (m+1)=5,
表示第3轮筛选后剩下人数的个数小于报数个数的(m+1), 所以最后出列的人的编号为第3次筛选后的第一个, 也就是17.
为什么选择第二次筛选后的结果呢?  因为此时还保留着位置信息loc
计算出第二次筛选后loc的位置为5, 则第一次筛选后的位置loc=(5-2)*m+1=10, 正好是17所在的位置数
同理, 原位置loc=(10-2)*m+1=17, 所以答案为17
	解释这里的公式(loc-2)*m+1
	loc-2 = loc-1-1，其中一个1是每轮游戏都要右移一次，所以位置信息要-1左移。
*/
/*
class Joseph {
public:
    int helper(int n, int m){
        int next_n = ceil(1.0*n/m);
        int next_m = m+1;
        if(next_n <= next_m){  // end state
            return (next_n-1)*m+1;
        }
        int loc = helper(next_n, next_m);  // m+1轮时最后一人编号的位置
        return (loc-2)*m+1;  // 当前第m轮时最后一人编号的位置
    }
    int getResult(int n) {
        if(n <= 0) return 0;
        return helper(n, 2);
    }
};
*/
int main()
{
    cout << Joseph().getResult(5) << endl;
    cout << Joseph().getResult(7) << endl;
    cout << Joseph().getResult(11) << endl;
    return 0;
}
