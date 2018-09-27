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
��������
��������ᡷ�ϵķ���
��s1=ABCDΪ���������ȷ���s1����ѭ����λ֮��õ���S2�Ľ����
ABCD->BCDA->CDAB->DABC->ABCD  .......
�������ǰ�ǰ�����ߵ����ݽ��б�����
ABCD->ABCDA->ABCDAB->ABCDABC->ABCDABCD.....
��˿�������s1��ѭ����λ�������ַ���S2�������ַ���s1+s1�����ַ��������s2������s1ѭ����λ�õ�����һ��������s1+s1�ϡ�
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
