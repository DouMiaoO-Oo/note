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
