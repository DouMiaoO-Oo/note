#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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
