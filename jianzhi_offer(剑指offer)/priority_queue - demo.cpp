#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;

priority_queue<int, vector<int>, std::greater<int> > minh; // 降序排列，小根堆
priority_queue<int, vector<int>, std::less<int> > maxh;  // 升序排列，大根堆
//vector<int> v;
vector<int> v({1,2,3,4});
vector<vector<bool> >vv = vector<vector<bool> >(10, vector<bool>(10, false));

int main(){
    for(int i = 0; i < 100; ++i){
        minh.push(i);
        maxh.push(i);
        //v.push_back(i);
    }
    cout << minh.top() << endl;
    cout << maxh.top() << endl;
    for(auto val: v){
        cout << val << ' ' << endl;
    } cout << endl;
    //vector<int> vv({1,2,3,4});

    char*  s1 = "hello";
    char  s2[] = "hello";
    s2[0] = 'H';
    cout << s2 << endl;
    return 0;
}
