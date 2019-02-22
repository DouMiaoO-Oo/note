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
class AntiOrder {
public:
    void merge(vector<int>& a, int l, int mid, int r){
        int l1 = l, l2 = mid+1, id = 0;
        vector<int> tmp(r-l+1);
        while(l1 <= mid && l2 <= r){
            if(a[l1] <= a[l2]){
                tmp[id++] = a[l1++];
            } else{
                tmp[id++] = a[l2++];
                cnt += mid+1-l1;
            }
        } while(l1 <= mid){
            tmp[id++] = a[l1++];
        } while(l2 <= r){
            tmp[id++] = a[l2++];
        } for(int i = 0; i < id; ++i){
            a[l+i] = tmp[i];
        } return;
    }
    void div(vector<int>& a, int l, int r){
        if(l < r){
            int mid = (l+r)/2;
            div(a, l, mid);
            div(a, mid+1, r);
            merge(a, l, mid, r);
        } return;
    }
    int count(vector<int> a, int n) {
        cnt = 0;
        div(a, 0, n-1);
        return cnt;
    }
private:
    int cnt;
};

/*
方法二： 迭代法
unsigned long long merge_sort(vector<int>& arr){
    unsigned long long  cnt = 0;
    int n = arr.size();
    if(n <= 1) return 0;
    vector<int> tmp(n);
    int ls, le, rs, re, id;
    for(int i = 1; i < n; i <<= 1){
        for(int index = 0; index+i<n; index += (i<<1)){
            id = 0, ls = index, le = index+i-1, rs = le+1, re = min(le+i, n-1);
            while(ls <= le && rs <= re){
                if(arr[ls] <= arr[rs]) tmp[id++] = arr[ls++];
                else {
                    tmp[id++] = arr[rs++];
                    cnt += (le-ls+1);
                }
            } while(ls <= le){  // enter this loop when rs = re+1
                arr[--rs] = arr[le--];
            } while(id > 0){  // end this loop when id == 0
                arr[--rs] = tmp[--id];
            }
        }
    } return cnt;
}
*/
int main(){

    return 0;
}
