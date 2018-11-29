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
    bool findMagicIndex(vector<int> A, int n) {
        int l = 0, r = n-1, mid;
        while(l <= r){
            mid = (l+r)/2;
            if(A[mid] == mid) return true;
            else if(A[mid] < mid){
                l = mid+1;
            } else{
                r = mid-1;
            }
        } return false;
    }
};
int main(){

    return 0;
}
