#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
class Replacement {
public:
    string replaceSpace(string iniString, int len) {
        int cnt = 0;
        for(int i = 0; i < len; ++i){
            if(iniString[i] == ' ') ++cnt;
        }
        int new_len = len+2*cnt;
        iniString.resize(new_len);
        for(int i = len-1, j = new_len-1; i>=0;){
            if(iniString[i] == ' '){
                iniString[j--] = '0';
                iniString[j--] = '2';
                iniString[j--] = '%';
                --i;
            } else{
                iniString[j--] = iniString[i--];
            }
        } return iniString;
    }
};
int main(){

    return 0;
}
