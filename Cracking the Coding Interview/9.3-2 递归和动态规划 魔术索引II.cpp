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
class MagicIndex {
public:
    /*
        没做出来

    bool findMagicIndex(vector<int> A, int n) {
        int l = 0, r = n-1, mid;
        while(l <= r){
            mid = (l+r)/2;
            cout << "A[mid]=" << A[mid] << " mid=" << mid << endl;
            if(A[mid] == mid){return true;}
            else if(A[mid] < mid){
                l = mid+1;
            } else{
                r = mid-1;
            }
        } return false;
    }*/
};
void find_(int* a, int n){
    for(int i = 0; i < n; ++i){
        if(a[i] == i){
            cout << i << endl;
            return;
        }
    } cout << "False" << endl;
}
int main(){
    int a[] = {0,0,1,1,3,4,5,6,6,8,9,9,11,11,11,11,12,14,14,14,14,16,18,18,18,20,20,22,24,24,24,26,28,30,30,32,32,32};
    int n = 38;
    find_(a, n);
    MagicIndex().findMagicIndex(vector<int>(a, a+n), n);
    return 0;
}
