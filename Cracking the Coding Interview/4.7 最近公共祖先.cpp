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
/*
此题有另一个开拓思路的解法：

每个编号转化成二进制，于是发现，每个节点A的2个儿子节点的二进制表示，是A的二进制表示后，右边分别追加0和1.
把10进制数转化成二进制串，从高位到低位，找最长公共前缀。这个前缀转化成十进制就是公共祖先了。
class LCA {
public:
    string int2b(int x){
        string ans="";
        while(x){
            ans=(char)((x&1)+'0')+ans;
            x/=2;
        }
        return ans;
    }
    int getLCA(int a, int b) {
        string sa=int2b(a);
        string sb=int2b(b);
        int ans=0;
        for(int i=0;i<sa.length()&&i<sb.length();i++){
            if(sa[i]==sb[i]) ans=ans*2+(sa[i]-'0');
            else break;
        }
        return ans;
    }
};
链接：https://www.nowcoder.com/questionTerminal/70e00e490b454006976c1fdf47f155d9
来源：牛客网

*/
class LCA {
public:
    int getLCA(int a, int b) {
        while(a != b){
            if(a>b) a >>= 1;
            else b >>= 1;
        } return a;
    }
};
int main(){

    return 0;
}
