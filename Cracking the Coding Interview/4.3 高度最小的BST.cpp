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
class MinimalBST {
public:
    /*
    高度最小即为完全二叉查找树
    完全二叉树满足这样的性质：2^(h-1) - 1 < n <= 2^h - 1
    其中h是二叉树的高度, n为节点数。
    所以用对数来求log2(n+1)，然后再向上取整数，
    */
    int buildMinimalBST(vector<int> vals) {
        return int(log(vals.size()+1)/log(2)+1);
    }
};
int main(){

    return 0;
}
