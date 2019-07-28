#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;

int NumberOf1(int n) {
         int cnt = 0;
         while(n){
             ++cnt;
             n &= (n-1);
         } return cnt;
     }

int main(){

    return 0;
}
