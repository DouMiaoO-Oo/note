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
	void replaceSpace(char *str, int length) {
		// 假定题目中的length是str的最大长度
        if((str == NULL) || (length == 0)) return;
        int len = 0, cnt = 0;
        for(int i = 0; str[i] != '\0'; ++i){
          ++len;
          if(str[i] == ' ') ++cnt;  
        }
		// assert(len == length); // assert failed
        int j = len+cnt*2; // take '\0' into account
        if(j>length) return;
        for(int i = len; i >= 0; --i){
            if(str[i] != ' ') {
                str[j--] = str[i];
            } else{
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            }
	    }
    }
};
int main(){
	
    return 0;
}
