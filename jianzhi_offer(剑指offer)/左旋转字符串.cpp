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
    void my_reverse(string& str, int s, int e){
        while(s<e){
            swap(str[s++], str[e--]);
        }
    }
    string LeftRotateString(string str, int n) {
        if(str == "" || n == 0) return str;
        n %= str.size();
        my_reverse(str, 0, n-1);
        my_reverse(str, n, str.size()-1);
        my_reverse(str, 0, str.size()-1);
        return str;
    }
};
int main(){

    return 0;
}
