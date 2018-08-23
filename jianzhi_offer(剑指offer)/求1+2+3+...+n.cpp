#include <iostream>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;

int Sum_Solution(int n){
    int res = 0;
    res += n--;
    n && (res += Sum_Solution(n));
    return res;
}

int main(){
	cout << Sum_Solution(10) << endl;
    return 0;
}
