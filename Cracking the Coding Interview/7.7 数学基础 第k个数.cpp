#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
#include <cmath>
#include<unordered_set>  // 需要c++ 11才能支持
using namespace std;
class KthNumber {
public:
    int findKth(int k) {
        int p3 = 1, p5 = 1, p7 = 1;
        vector<int> v(101, 0);
        v[1] = 3;
        v[2] = 5;
        v[3] = 7;
        // assert k>0 && k<=100
        for(int i = 4; i <= k; ++i){
            while(v[p3]*3 <= v[i-1]) ++p3;
            while(v[p5]*5 <= v[i-1]) ++p5;
            while(v[p7]*7 <= v[i-1]) ++p7;
            v[i] = min(v[p3]*3, min(v[p5]*5, v[p7]*7));
        }
        return v[k];
    }
};
int main(){
    return 0;
}
