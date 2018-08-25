#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int GetUglyNumber_Solution(int index) {
        vector<int> v(index+5, 0);
        v[0] = 1;
        v[1] = 2;
        v[2] = 3;
        v[3] = 4;
        v[4] = 5;
        int id = 4;  // index of the last ugly number
        int i2 = 0, i3 = 0, i5 = 0;
        while(id < index){
            while((v[i2]<<1) <= v[id]) ++i2;
            while(v[i3]*3 <= v[id]) ++i3;
            while(v[i5]*5 <= v[id]) ++i5;
            v[++id] = min(v[i2]<<1, min(v[i3]*3, v[i5]*5));
        } return v[index-1];
}
int main(){
    for(int i = 0; i < 100; ++i){
        cout << GetUglyNumber_Solution(i) << endl;
    }
    return 0;
}
