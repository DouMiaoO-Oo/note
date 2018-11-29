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
class Finder {
public:
    int findElement(vector<int> A, int n, int x) {
        // assert A[i] != A[j] for i != j  保证元素互异
        // 共有6种情况，画图即可
        /* 一: x > A[mid]                 二: x < A[mid]
        1. A[mid] > A[l],               1. A[l] < x,
            l = mid+1                          r = mid-1
        2.x > A[r] && A[mid] < A[l],    2. x < A[l] && A[l]<A[mid] ,
            r = mid-1                          l = mid+1
        3.A[l] > x,                     3. A[l] > A[mid], // 或者 A[mid]<=A[r]
            l = mid+1                          r = mid-1
        */
        int l = 0, r = n-1, mid;
        while(l <= r){
            mid = (l+r)/2;
            if(A[mid] == x) return mid;
            if(A[mid] < x){
                if(x>=A[l] && A[l] > A[mid]){
                    // 等价于 x>A[r] && A[l] > A[mid]
                     r = mid-1;
                } else l = mid+1;
            } else{
                if(x<A[l] && A[l] < A[mid]){
                    l = mid+1;
                } else r = mid-1;
            }
        } return -1;
    }
};
int main(){

    return 0;
}
