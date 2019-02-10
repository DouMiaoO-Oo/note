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
int cmp(int a, int b){
    return a<b;  // 升序排列
}
/* 对比一下sort中的cmp和less<int>，他们的逻辑是一致的 */
class Middle {
public:
    vector<int> getMiddle(vector<int> A, int n) {
        vector<int> res;
        if(n <= 0) return res;
        // n为偶数时，中位数是较小的那个
        priority_queue<int, vector<int>, std::less<int> > max_heap;
        priority_queue<int, vector<int>, std::greater<int> > min_heap;
        for(int i = 0; i < n; ++i){
            if(max_heap.empty() || max_heap.top() >= A[i]){
                max_heap.push(A[i]);
            } else{
                min_heap.push(A[i]);
            }
            if(max_heap.size() == min_heap.size()+2){
                min_heap.push(max_heap.top());
                max_heap.pop();
            } else if(max_heap.size() < min_heap.size()){
                max_heap.push(min_heap.top());
                min_heap.pop();
            } res.push_back(max_heap.top());
        } return res;
    }
};
int main(){
    int n = 10;
    int a[n];
    for(int i = 0; i < n; ++i){
        a[i] = n-i;
    }
    for(int i = 0; i < n; ++i){
        cout << a[i] << " ";
    } cout << endl;
    sort(a, a+n);
    for(int i = 0; i < n; ++i){
        cout << a[i] << " ";
    } cout << endl;
    sort(a, a+n, cmp);
    for(int i = 0; i < n; ++i){
        cout << a[i] << " ";
    } cout << endl;
    return 0;
}
