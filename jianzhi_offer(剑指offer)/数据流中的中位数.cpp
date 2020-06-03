#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;

// 2018.9.6
class Solution {
private:
    priority_queue<int, vector<int>, std::greater<int> > min_q;
    priority_queue<int, vector<int>, std::less<int> > max_q;

public:
    void Insert(int num)
    {
        if(max_q.empty() || num > max_q.top()){
            min_q.push(num);
        } else{
            max_q.push(num);
        } if(max_q.size()+2 == min_q.size()){  // 2020.5.9 → min_q.size()-max_q.size() == 2 → min_q.size()-max_q.size() > 1 这时就不能通过，应该跟size()函数的unsigned int有关
            max_q.push(min_q.top());
            min_q.pop();
        } else if(max_q.size() == min_q.size()+1){
            min_q.push(max_q.top());
            max_q.pop();
        }
    }

    double GetMedian()
    {
        if(max_q.size() == min_q.size()){
            return (max_q.top()+min_q.top())/2.0;
        } else{
            return min_q.top();
        }
    }

};

int main(){
    Solution solution = Solution();
    priority_queue<int, vector<int>, std::greater<int> > min_queue;
    for(int i = 10; i >= 0; --i){
        min_queue.push(i);
    } cout << min_queue.top() << endl;
    return 0;
}
