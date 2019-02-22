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
现在我们有一个int数组，请你找出数组中每个元素的下一个比它大的元素。

给定一个int数组A及数组的大小n，请返回一个int数组，代表每个元素比他大的下一个元素,若不存在则为-1。保证数组中元素均为正整数。

测试样例：
[11,13,10,5,12,21,3],7
返回：[13,21,12,12,21,-1,-1]

用例:
[10981,271060,231334,254597,248942,180532,80446,198879,41046,255511,213723,94347,247318,163859,276728,209984,7709,22319,141820,106671,126322,255849,112409],23
对应输出应该为:
[271060,276728,254597,255511,255511,198879,198879,255511,255511,276728,247318,247318,276728,276728,-1,255849,22319,141820,255849,126322,255849,-1,-1]

*/

class NextElement {
public:
    /* 所有A中的数字只在stack中访问了一遍，所以复杂度是 O(n) */
    vector<int> findNext(vector<int> A, int n) {
        if(n <= 0) return vector<int>();
        vector<int> res(n);
        stack<int> s;
        for(int i = n-1; i >= 0; --i){
            while(!s.empty() && A[i] >= s.top()){
                s.pop();
            } if(!s.empty()){
                res[i] = s.top();
            } else{
                res[i] = -1;
            } s.push(A[i]);
        } return res;
    }
};

/*
另一种方法，思路也很有趣
import java.util.*;
public class NextElement {
    public int[] findNext(int[] A, int n) {
        // write code here
        Stack<Integer> stack=new Stack<Integer>();
        for(int i=0;i<A.length;i++){
            while(!stack.isEmpty()&&A[stack.peek()]<A[i]){
                A[stack.pop()]=A[i];
            }
            stack.add(i);  // 还没有找到下一个最大值的元素的下标
        }
        while(!stack.empty())
            A[stack.pop()]=-1;
        return A;
    }
}
链接：https://www.nowcoder.com/questionTerminal/11ae41035eef4ed9b354d0752f5abc6f
*/

int main(){

    return 0;
}
