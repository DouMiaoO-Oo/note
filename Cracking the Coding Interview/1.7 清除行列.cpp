#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
#include <cmath>
using namespace std;


/*
思路1：
新建一个同样大小矩阵标记零元素出现的位置，然后在第二次遍历矩阵时将被标记的元素赋值为0
时间&空间复杂度为0(MN)。

思路2：
如果一行（列）中有一个零元素或者多个，这行（列）都要被赋值为0。
定义两个数组分别表示行、列是否有零元素，在第一次遍历的时候赋值这两个数组
第二次遍历的时候，根据这两个数组的内容，将对应位置元素赋值为0。
所以这样所需要的存储空间是O(M+N)。

*/
/*
如果是删除所在的行、列此题怎么做比较好？
*/
class Clearer {
public:
    vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
        vector<bool> row(n, false), col(n, false);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(mat[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(row[i] || col[j])
                    mat[i][j] = 0;
        return mat;
    }
};
int main(){
	
    return 0;
}
