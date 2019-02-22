#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
/*
因为出现偶数次的数字，异或操作之后会变成0. 例如2^2^13^13=0
我们用0将数组data中全部的数字异或操作一遍，得到结果 t = num1^num2
任取t的二进制表达式中等于1的某一位，那么num1和num2的二进制表达式在这一位上不同。
此时我们根据这一位将data中的数字分为两组(1或者0)，然后每一组单独做异或操作，则此时两组异或得到的结果就是我们所需要的答案。

e.g., data={2, 2, 7, 7, 3, 6}, t=3^6=2'011^2'110 = 2'101
可以发现二进制t最左边和最右边的数字是2'1
我们取最右边的一位，根据这一位取0或者1将data中的数字分类:
{2, 2, 6}, {7, 7, 3}. 将这两组分别进行异或操作就可以得到答案： 2^2^6=6, 7^7^3=3
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		// assert data.size()>=2 && data.size()%2 == 0
        int t = 0, id = 1;
        for(int i = 0; i < data.size(); ++i) t ^= data[i];
        while(id&t != 1) id <<= 1;
        *num1 = 0, *num2 = 0;
        for(int i = 0; i < data.size(); ++i){
            if(data[i]&id) *num1 ^= data[i];
             else *num2 ^= data[i];
        }
    }
};
int main(){

    return 0;
}
