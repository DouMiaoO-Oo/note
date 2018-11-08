#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
#include <cmath>
#include<unordered_set>  // 需要c++ 11才能支持
using namespace std;

class Render {
public:
    vector<int> renderPixel(vector<int> screen, int x, int y) {
        for(int i = x; i <= y; ++i){
            screen[i/8] |=  1<<(i%8);
        } return screen;
    }
};
int main(){

    return 0;
}
