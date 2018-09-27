#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
class UnusualAdd {
public:
/* ����Ҳ������ */
    int addAB(int a, int b) {
       int c; // carry
       while(b != 0){
           c = (a&b)<<1;
           a = a^b;
           b = c;
       } return a;
    }
};
int main(){
    int x, y;
    while(cin >> x >> y){
        cout << UnusualAdd().addAB(x, y) << endl;
    }
    return 0;
}
