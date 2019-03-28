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


class Rearrange {
public:
/*
参考链接：https://www.nowcoder.com/questionTerminal/091c2f1cf441484f81696f08328b06cd

进行两次遍历，一次从右到左找出M, 一次从左到右找出N
（1）从右到左找出M
如果当前元素A[i]大于之前的最小元素则说明当前元素A[i]应处于[M N]无序序列中
因为之前的最小元素应该放置在i这个位置
而且当前元素是当前最小下标的无序元素所以更新M为当前元素下标
（2）从左到右找出N
如果当前元素A[i]小于之前的最大元素则说明当前元素A[i]应处于[M N]无序序列中
因为之前的最大元素应该放置在i这个位置
而且当前元素是当前最大下标的无序元素所以更新N为当前元素下标。
*/
    vector<int> findSegment(vector<int> A, int n) {
        if(A.size() == 0 || A.size() != n) return vector<int>();
        int maxv = A[0], minv = A[n-1], M = 0, N = 0;
        for(int i = n-2; i >= 0; --i){
            if(A[i] <= minv) minv = A[i];
            else M = i;
        }
        for(int i = 1; i < n; ++i){
            if(maxv <= A[i]) maxv = A[i];
            else N = i;
        } int res[] = {M, N};
        return vector<int>(res, res+2);
    }
};

int main(){

    return 0;
}
