#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

class MyDeque{
    public:
    void pop(){
        dq.pop_front();
    }
    void push(int x){
        while(!dq.empty() && dq.back() < x){
            dq.pop_back();
        } dq.push_back(x);
    }
    int get_max(){
        return dq.front();
    }
    private:
    deque<int> dq;
};
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size){
        MyDeque myDeque;
        vector<int> res;
        if(num.size() == 0 || size == 0) return res;
        if(size > num.size()) return res; //size = num.size();
        for(int i = 0; i < size-1; ++i){
            myDeque.push(num[i]);
        } for(int i = size-1; i < num.size(); ++i){
            myDeque.push(num[i]);
            res.push_back(myDeque.get_max());
            if(myDeque.get_max() == num[i-size+1]){
                myDeque.pop();
            }
        } return res;
       
    }
};
int main(){

    return 0;
}
