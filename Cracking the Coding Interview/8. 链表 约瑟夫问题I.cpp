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
题目描述：
约瑟夫问题是一个非常著名的趣题，即由n个人坐成一圈，按顺时针由1开始给他们编号。然后由第一个人开始报数，数到m的人出局。现在需要求的是最后一个出局的人的编号。

给定两个int n和m，代表游戏的人数。请返回最后一个出局的人的编号。保证n和m小于等于1000。

测试样例：
5 3
返回：4
*/
class Joseph {
public:
    int getResult(int n, int m) {
        // 循环数组版本, 也可以用链表
        // 可以用bool类型来做
        vector<int> v(n);
        for(int i = 0; i < n; ++i){
            v[i] = i+1;
        } int id = 0, cnt = 0, leave = 1;
        while(leave < n){
            if(v[id] > 0){
                if(++cnt == m){
                    cnt = 0;
                    v[id] *= -1;
                    ++leave;
                }
             } if(++id == n){
                id = 0;
             }
        }
        for(int i = 0; i < n; ++i){
            if(v[i] > 0){
                return i+1;
            }
        } return -1;
    }
};
/*
参考链接：https://www.nowcoder.com/questionTerminal/11b018d042444d4d9ca4914c7b84a968


首先在不影响题意的情况下对题目进行修改：把n个人的编号改为0~n-1，然后我们对出列的过程进行分析。
第一个出列的人的编号是(m-1)%n，我们将编号记为k，则剩余的编号为(0,1,...,k-1,k+1,...,n-1)。
第一个人(编号是k) 出列之后，剩下的n-1个人组成了一个新的长度为 (n-1) 的约瑟夫环（以编号为k+1的人开始）:  (k+1,...,n-1,0,1,...k-1)

对于有n个人（编号从0到n-1）每报数到m时出列的约瑟夫环游戏，我们用f(n,m)表示最后出列者的编号。
用q(n-1,m)表示从(k+1,...,n-1,0,1,...k-1)开始，每报数到m时出列的约瑟夫环，游戏结束时的最后出列者的编号。
则f(n,m)=q(n-1,m)。

下面把(k+1,...,n-1,0,1,...k-1)转换为(0~n-2)的形式，即
k+1对应0
k+2对应1
...
k-1对应n-2
转化函数设为p(x)=(x-k-1)%n, p(x)的逆函数为p^{-1}(x)=(x+k+1)%n
    关于取模的逆运算，可以参考 http://tieba.baidu.com/p/4856530597
    因为我们关注的是有限域 0~n-1，所以显然 (x+k)%n 的逆运算就是 (x-k)%n
    注意, p(x)中包括参数k和n，而k=(m-1)%n
则f(n,m)=q(n-1,m)=p^{-1}(f(n-1,m))=(f(n-1,m)+k+1)%n
又因为k=(m-1)%n，可得: f(n,m)=(f(n-1,m)+m)%n;

最终的递推关系式为
f(1,m) = 0;                        (n=1)
f(n,m)=(f(n-1,m)+m)%n; （n>1）
*/
int getResult(int n, int m){
    int loc = 0;
    for(int i = 2; i <= n; ++i){
        loc = (loc+m)%i;
    } return loc+1;
}
int main()
{
    int n = 100, m=3;
    cout << Joseph().getResult(n, m) << endl;
    cout << getResult(n, m) << endl;
    return 0;
}
