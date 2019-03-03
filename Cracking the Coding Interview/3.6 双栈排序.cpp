#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;

/*
按升序对栈进行排序（即最大元素位于栈顶），要求最多只能使用一个额外的栈存放临时数据，不得使用其他数据结构。
给定一个int[] numbers(C++中为vector<int>)，其中第一个元素为栈顶，请返回排序后的栈。
请注意这是一个栈，意味着排序过程中你只能访问到栈顶元素。
测试样例：
	[1,2,3,4,5]
	返回：[5,4,3,2,1]
*/
class TwoStacks {
public:
    /*目标是将num按照降序排列*/
    vector<int> twoStacksSort(vector<int> num) {
        // asstert !num.empty()
        stack<int> s;
        while(!num.empty()){
            int cur = num.back();
            num.pop_back();
            while(!s.empty() && cur < s.top()){
                num.push_back(s.top());
                s.pop();
            } s.push(cur);
            while(s.empty() || num.back() >= s.top()){
                s.push(num.back());
                num.pop_back();
            }
        } while(!s.empty()){
            num.push_back(s.top());
            s.pop();
        } return num;
    }
};
/* 
这段代码速度更快，但是不知道原理。 这道理某些写法会超时
链接：https://www.nowcoder.com/questionTerminal/d0d0cddc1489476da6b782a6301e7dec
来源：牛客网
 */
class TwoStacks2 {
public:
    /*目标是将num按照降序排列*/
    vector<int> twoStacksSort(vector<int> num) {
       
        stack<int> s;
        while(!num.empty()){
            int cur = num.back();
            num.pop_back();
            while(!s.empty() && cur < s.top()){
                num.push_back(s.top());
                s.pop();
            } s.push(cur);
        } while(!s.empty()){
            num.push_back(s.top());
            s.pop();
        } return num;
    }
};

/*
这段代码会超时
class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> arr) {
        // 最后一个元素为栈底, 降序排列数组
        stack<int> s;
        while(!arr.empty()){
            if(s.empty() || arr.back() >= s.top()){
                s.push(arr.back());
                arr.pop_back();
            } else{
                int back = arr.back();
                arr.pop_back();
                while(!s.empty()){
                    arr.push_back(s.top());
                    s.pop();
                } s.push(back);
            }
        }
        while(!s.empty()){
            arr.push_back(s.top());
            s.pop();
        } return arr;
    }
};
*/
int main(){

    return 0;
}
