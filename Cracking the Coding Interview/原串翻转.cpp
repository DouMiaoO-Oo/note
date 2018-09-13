#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
class Reverse {
public:
    string reverseString(string iniString) {
        // write code here
        for(int i = 0, j = iniString.size()-1; i<j; ++i, --j){
            swap(iniString[i], iniString[j]);
        } return iniString;
    }
};
int main(){

    return 0;
}
