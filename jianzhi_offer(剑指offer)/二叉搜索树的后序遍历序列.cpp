#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        /* Postorder: left->right->root */
        if(sequence.size() == 0) return false;  // 题目要求空树为false
        return helper(sequence, 0, sequence.size()-1);
    }
private:
    bool helper(vector<int>& arr, int l, int r){
        if(l >= r) return true;
        int root_val = arr[r];
        int rid = l; // start id of right tree
        while(rid < r && arr[rid] < root_val) ++rid;
        for(int i = rid; i < r; ++i){
            if(arr[i] < root_val) return false;
        }  return helper(arr, l, rid-1) && helper(arr, rid, r-1);
    }
};

/*
方法二：
非递归版本，操作的时间复杂度应该和递归版本一致？但是在while循环中多检验了一部分节点的值
题目中假设了树中的每个节点值各不相同。

*/
/*
牛客网参考链接：https://www.nowcoder.com/questionTerminal/a861533d45854474ac791d90e447bafd

思路解析：
非递归也是一个基于递归的思想。
我们将原来的树去掉根后，左右两边的子树分别记为left_0, right_0. 且left_0一定比right_0要小。
right_0的最后一个数字是右子树的根, 也会比left_0中所有的值要大。
因为左子树的所有值都比右子树的根小，我们可以把left_0当做right_0的左子树一起处理，
只需要特别的验证right_0的右子树是否符合条件。
如此思路迭代下去即可。

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int size = sequence.size();
        if(0==size)return false;
 
        int i = 0;
        while(--size){
            while(sequence[i]<sequence[size]) ++i;
            while(sequence[i]>sequence[size]) ++i;
 
            if(i<size)return false;
            i=0;
        }
        return true;
    }
};
*/
int main(){

    return 0;
}
