/*
描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。
1.模式中的字符'.'表示任意一个字符
2.模式中的字符'*'表示它前面的字符可以出现任意次（包含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

数据范围:
    1.str 只包含从 a-z 的小写字母。
    2.pattern 只包含从 a-z 的小写字母以及字符 . 和 *，无连续的 '*'。
    3. 0 \le str.length \le 26 \0≤str.length≤26 
    4. 0 \le pattern.length \le 26 \0≤pattern.length≤26 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        // if(str == NULL && pattern == NULL) return false;
        if(*str == '\0' && *pattern == '\0') return true;
        if(*str != '\0' && *pattern == '\0') return false;
        // assert(*pattern != '\0')
        if(*(pattern+1) != '*'){
            if(*pattern == '.' && *str != '\0'){
                return match(str+1, pattern+1);
            } else{
                if(*str != *pattern) return false;
                return match(str+1, pattern+1);
            }
        }

        if(*str == *pattern
           || (*pattern == '.' && *str != '\0')){
            return match(str+1, pattern) ||
                match(str+1, pattern+2) ||
                match(str, pattern+2);
        }
        return match(str, pattern+2);
        //return false;
    }
};
int main(){
    char str[] = "", pattern[] = ".*";
    cout << Solution().match("", ".*") << endl;
    return 0;
}
