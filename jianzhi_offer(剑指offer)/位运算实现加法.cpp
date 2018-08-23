#include <iostream>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;
// 这个方法负数也成立
int Add(int x, int y)
{
    int res = x^y;  // 这里只能用异或
    int c = x&y;  // carry
    while(c != 0){
        x = res;
        y = (c<<1);
        res = x^y;
        c = x&y;
    } return res;
}
int main(){
	//cout << Add(12, 33) << endl;
	int x, y;
	while(cin >> x >> y){
        cout << Add(x, y) << endl;
	}
    return 0;
}
