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
    void reOrderArray(vector<int> &array){
        /* 方法一：冒泡排序 每次将一个偶数放置到最终的位置
            复杂度O(n^2)
        */
        if(array.size() <= 1) return;
        for(int i = 0; i < array.size()-1; ++i){
            for(int j = 0; j < array.size()-1-i; ++j){
                if( !(array[j]&1) && (array[j+1]&1)){
                    swap(array[j], array[j+1]);
                }
            }
//            for(int j = 0; j < array.size(); ++j){
//                cout << array[j] << ' '; // 打印出来观察
//            } cout << endl;
        } return;

        /* it will change the relatively order
        int l = 0, r = array.size()-1;
        while(l<r){
            while((l<r) && (array[l]&1)) ++l;
            while((l<r) && !(array[r]&1)) --r;
            swap(array[l++], array[r--]);
        } return;
        */
    }
};
void reOrderArray(vector<int> &array) {
    /* 方法二： 时间与空间的复杂度均为O(n) */
        int n = array.size();
        if(n <= 1) return;
        int j = 0;
        for(int i = 0; i < n; ++i){
            if(array[i]&1) ++j;
        }
        vector<int> v(n);
        for(int i = 0, id = 0; id < n; ++id){
            if(array[id]&1){
                v[i++] = array[id];
            } else{
                v[j++] = array[id];
            }
        } array = vector<int>(v.begin(), v.end());
}
int main(){
    int a[] = {2,4,6,8,0,1,3,5,7};
    vector<int> v(a, a+9);
    Solution().reOrderArray(v);
    for(int i = 0; i < 9; ++i){
        cout << v[i] << ' ';
    } cout << endl;
    return 0;
}
