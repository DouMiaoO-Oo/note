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
有一个排过序的数组，包含n个整数，但是这个数组向左进行了一定长度的移位，例如，原数组为[1,2,3,4,5,6]，向左移位5个位置即变成了[6,1,2,3,4,5],现在对于移位后的数组，需要查找某个元素的位置。请设计一个复杂度为log级别的算法完成这个任务。

给定一个int数组A，为移位后的数组，同时给定数组大小n和需要查找的元素的值x，请返回x的位置(位置从零开始)。保证数组中元素互异。

测试样例：
[6,1,2,3,4,5],6,6
返回：0
*/
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
