#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
        return;
    }
    int pop() {
        int res;
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // assert (!stack2.empty());
        res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
int main(){

    return 0;
}
