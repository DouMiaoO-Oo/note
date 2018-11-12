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
class CloseNumber {
public:
    int getLarger(int x){
        /* from right bit to left bit: 0 -> 1 -> 0
            `state` from 0 -> 1-> 2
        */
        int state = 0;
        int pos = 1;
        int larger;
        int c0 = 0;
        int c1 = 0;
        // find larger
        while(state != 2){
            if((x&pos) == 0){
                if(state == 1){
                    state = 2;
                } else{
                    pos <<= 1;
                    ++c0;
                }
            } else {
                pos <<= 1;
                state = 1;
                ++c1;
            }
        }
        larger = x|pos;
        unsigned int t = 1;  // ~t需要是无符号数
        for(int i = 1; i < c1; ++i){
            larger |= t;
            t<<=1;
        }
        for(int i = c1; i <= c0+c1; ++i){
            larger &= (~t);
            t<<=1;
        } return larger;
    }
    int getLess(int x){
        /* from right bit to left bit: 1 -> 0 -> 1
            `state` from 0 -> 1-> 2
        */
        int state = 0;
        unsigned int pos = 1;
        int less;
        int c0 = 0;
        int c1 = 0;
        // find larger
        while(state != 2){
            if((x&pos) == 0){ // 只能判断是不是等于0
                pos <<= 1;
                state = 1;
                ++c0;
            } else {
                if(state == 1){
                    state = 2;
                } else{
                    pos <<= 1;
                    ++c1;
                }
            }
        }
        less = x&(~pos);
        unsigned int t = 1;
        for(int i = 1; i < c0; ++i){
            less &= (~t);
            t<<=1;
        }
        for(int i = c0; i <= c0+c1; ++i){
            less |= t;
            t<<=1;
        } return less;
    }
    vector<int> getCloseNumber(int x) {
        vector<int> res;
        res.push_back(getLess(x));
        res.push_back(getLarger(x));
        return res;
    }
};
int main(){
    CloseNumber closeNumber;
    cout << closeNumber.getLarger(2) << endl;  // 00010
    cout << closeNumber.getLess(2) << endl;  // 00010
    return 0;
}
