#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
class Same {
public:
    bool checkSam(string stringA, string stringB) {
        // write code here
        vector<int> a(256, 0);
        for(int i = 0; i < stringA.size(); ++i){
            ++a[(int)stringA[i]];
        } for(int i = 0; i < stringB.size(); ++i){
            --a[(int)stringB[i]];
        }
        for(int i = 0; i < 256; ++i){
            if(a[i] != 0) return false;
        } return true;
    }
};
int main(){
    return 0;
}
