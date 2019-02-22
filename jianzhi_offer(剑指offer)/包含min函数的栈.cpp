#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;

/*
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O(1)）
*/
class Solution {
public:
    void push(int val) {
        s1.push(val);
        if(s2.empty() || val <= s2.top()) {
            s2.push(val);
        }
    }
    void pop() {
        // assert !s1.empty()
        if(s1.top() == s2.top()){
            s2.pop();
        } s1.pop();
    }
    int top() {
        // assert !s1.empty()
        return s1.top();
    }
    int min() {
        return s2.top();
    }
private:
    stack<int> s1, s2;
};
int main(){

    return 0;
}
