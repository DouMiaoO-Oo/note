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
int main(){

    return 0;
}
