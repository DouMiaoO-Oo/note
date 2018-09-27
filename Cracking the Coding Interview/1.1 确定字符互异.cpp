#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
class Different {
public:
    bool checkDifferent(string iniString) {
        if(iniString.size()>256) return false;
        for(int i = 0; i < iniString.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(iniString[j] == iniString[i])
                    return false;
            }
        } return true;
    }
};
int main(){

    return 0;
}
