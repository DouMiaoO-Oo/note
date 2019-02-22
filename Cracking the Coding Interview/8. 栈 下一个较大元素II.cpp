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
题目描述
现在有一个数组，请找出数组中每个元素的后面比它大的最小的元素，若不存在则为-1。

给定一个int数组A及数组的大小n，请返回每个元素所求的值组成的数组。保证A中元素为正整数，且n小于等于1000。

测试样例：
[11,13,10,5,12,21,3],7
[12,21,12,12,21,-1,-1]
*/
class NextElement {
public:
// 暴力冒泡排序
    vector<int> findNext(vector<int> A, int n){
        if(n <= 0) return vector<int>();
        vector<int> res(n, -1);
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                if(A[i] < A[j]){
                    if(res[i] == -1) {
                        res[i] = A[j];
                    } else{
                        res[i] = min(res[i], A[j]);
                    }
                }
            }
        } return res;
    }
};
/*
// 方法二： 双栈排序
class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        if(n <= 0) return vector<int>();
        stack<int> s1, s2;
        vector<int> res(n, -1);
        for(int i = n-1; i >= 0; --i){
            while(!s1.empty() && A[i] >= s1.top()){
                s2.push(s1.top()); 
                s1.pop();
            } if(!s1.empty()){
              res[i] = s1.top();  
            }
            s1.push(A[i]);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        } return res;
    }
};
*/
int main(){

    return 0;
}
