#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
class ReverseEqual {
public:
    bool checkReverseEqual(string s1, string s2) {
        // write code here
        if(s1.size() == 0 || s1.size() != s2.size()) return false;
        int len = s1.size(), j, cnt;
        for(int i = 0; i < s1.size(); ++i){
            for(j = i, cnt = 0; cnt<len; j=(++j)%len, ++cnt){
                if(s1[cnt] != s2[j]) break;
            } if(cnt == len) return true;
        } return false;
    }
};
/*
方法二：
《编程珠玑》上的方法
以s1=ABCD为例，我们先分析s1进行循环移位之后得到的S2的结果：
ABCD->BCDA->CDAB->DABC->ABCD  .......
假设我们把前面移走的数据进行保留：
ABCD->ABCDA->ABCDAB->ABCDABC->ABCDABCD.....
因此看出，对s1做循环移位，所得字符串S2都将是字符串s1+s1的子字符串。如果s2可以由s1循环移位得到，则一定可以在s1+s1上。
if(s1.size() == 0 || s1.size() != s2.size()) return false;
string str = s1 + s1;
if(str.find(s2) != -1){
    return true;
} return false;
*/
int main(){
    string s1 = "ookvnorsiwwddjkpqasgbqjqrgsyriuxsruxidwprrxagjxzbwwgztsgndyfoelcgfzqzxzximtdwjlkhouxqrdzdguhxweqkvqabcltywygpbgeprmhbltnhkhynvpuszoqdrspwldgecrbvzsiywkfzphczpxyeyzhdhnegmodldikwnjhlwer";
    string s2 = "sgndyfoelcgfzqzxzximtdwjlkhouxqrdzdguhxweqkvqabcltywygpbgeprmhbltnhkhynvpuszoqdrspwldgecrbvzsiywkfzphczpxyeyzhdhnegmodldikwnjhlwerookvnorsiwwddjkpqasgbqjqrgsyriuxsruxidwprrxagjxzbwwgzt";
    cout << ReverseEqual().checkReverseEqual(s1, s2);
    return 0;
}
