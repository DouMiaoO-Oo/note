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
现在我们要读入一串数，同时要求在读入每个数的时候算出它的秩，即在当前数组中小于等于它的数的个数(不包括它自身)
请设计一个高效的数据结构和算法来实现这个功能。

给定一个int数组A，同时给定它的大小n，请返回一个int数组，元素为每次加入的数的秩。保证数组大小小于等于5000。

测试样例：
[1,2,3,4,5,6,7],7
返回：[0,1,2,3,4,5,6]
*/

class Rank {
public:
    vector<int> getRankOfNumber(vector<int> A, int n) {
        multiset<int> s;
        vector<int> res;
        if(A.size() == 0 || n <= 0) return res;
        for(int i = 0; i < A.size(); ++i){
            multiset<int>::iterator ub = s.upper_bound(A[i]); // > A[i]
            int rank = 0;
            for(auto it = s.begin(); it != ub; ++it){
                 ++rank;
            } s.insert(A[i]);
            res.push_back(rank);
        } return res;
    }
};
int main(){

    return 0;
}
