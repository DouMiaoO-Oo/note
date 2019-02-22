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
/*2019.2.20  修改了my_dq 的pop函数
class my_dq{
public:
    void push(int x){
        while(!dq.empty() && dq.back()<x){
            dq.pop_back();
        } dq.push_back(x);
    }
    int get_max(){
        return dq.front();
    }
    void pop(int x){
        if(dq.front() == x) dq.pop_front();
    }
private:
    deque<int> dq;
};
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size){
        vector<int> res;
        if(num.size() == 0 || size == 0 || size > num.size()) return res;
        dq = my_dq();
        for(int i = 0; i < size; ++i) dq.push(num[i]);
        res.push_back(dq.get_max());
        for(int i = size; i < num.size(); ++i){
            dq.push(num[i]);
            dq.pop(num[i-size]);
            res.push_back(dq.get_max());
        } return res;
    }
private:
    my_dq dq;
};
*/
int main(){

    return 0;
}
