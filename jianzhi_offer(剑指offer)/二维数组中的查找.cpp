#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
/*
数组是从左到右，从上到下递增。
那么从左下角a[m-1][0]开始
	如果当前的值小于target，因为a[i][0]≤a[m-1][0]都不符合条件，所以应该丢弃第一列。
	如果当前的值大于target，因为a[m-1][j]≥a[m-1][0]都不符合条件，所以应该丢弃最后一行。
*/
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > a) {
        int m = a.size();
        if(m == 0) return false;
        int n = a[0].size();
        if(n == 0) return false;
        int i = m-1, j = 0;
        while(i >= 0 && j < n){
            if(target == a[i][j]) return true;
            if(target < a[i][j]) ++j;
            else --i;
        } return false;
    }
};
int main(){

    return 0;
}
