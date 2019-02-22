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
    vector<int> multiply(const vector<int>& A) {
        if(A.size() <= 1) return vector<int>();
        vector<int> l(A.size()), r(A.size());
        l[0] = A[0]; 
        r[A.size()-1] = A[A.size()-1];
        for(int i = 1; i < A.size(); ++i){
            l[i] = l[i-1]*A[i];
        }
        for(int i = A.size()-2; i >= 0; --i){
            r[i] = r[i+1]*A[i];
        }
        vector<int> B(A.size());
        for(int i = 1; i < A.size()-1; ++i){
            B[i] = l[i-1]*r[i+1];
        } B[0] = r[1];
        B[A.size()-1] = l[A.size()-2];
        return B;
    }
};
int main(){

    return 0;
}
