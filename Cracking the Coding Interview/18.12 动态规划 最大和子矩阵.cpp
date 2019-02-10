#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <sstream>
#include <cmath>
#include <unordered_set>  // 需要c++ 11才能支持
#include <unordered_map>  // 需要c++ 11才能支持
using namespace std;
class SubMatrix {
public:
    int sumOfSubMatrix(vector<vector<int> > mat, int n) {
        if(n <= 0) return 0;
        vector<vector<int> > row(n, vector<int>(n, 0)),
        col(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i){
            row[i][0] = mat[i][0];
            col[0][i] = mat[0][i];
        }
        for(int i = 0; i < n; ++i){
            for(int j = 1; j < n; ++j){
                row[i][j] = row[i][j-1] + mat[i][j];
            }
        }
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < n; ++j){
                col[i][j] = col[i-1][j] + mat[i][j];
            }
        }
        /*cout << "row\n";
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout << row[i][j] << " ";
            } cout << endl;
        }*/
        // 利用m[i][j]来保存每个以mat(1,1), (i,j)作为端点的子矩阵和。最外圈是"哨兵"
        vector<vector<int> > m(n+1, vector<int>(n+1, 0));
        for(int i = 1; i <= n; ++i){
            m[i][1] = col[i-1][0];
            m[1][i] = row[0][i-1];
        }
        for(int i = 2; i <= n; ++i){
            for(int j = 2; j <= n; ++j){
                m[i][j] = m[i][j-1] + col[i-1][j-1];
            }
        }
        /*
        cout << "m\n";
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= n; ++j){
                cout << m[i][j] << " ";
            } cout << endl;
        }
        //*/
        int res = m[1][1];
        for(int i = 1; i <= n; ++i){
            for(int ii=i; ii <= n; ++ii){
                for(int j = 1; j <= n; ++j){
                    for(int jj = j; jj <= n; ++jj){
                        res = max(res,
                                  m[ii][jj] - m[ii][j-1]- m[i-1][jj] + m[i-1][j-1]);
                    }
                }
            }
        } return res;
    }
};
void test1(){
    int n = 3;
    vector<vector<int> > mat(n, vector<int>(n, 0));
    int a[] = {1, 2, -3, 3, 4, -5, -5, -6, -7};
    for(int i = 0; i < n*n; ++i){
        mat[i/n][i%n] = a[i];
    }
    cout <<  SubMatrix().sumOfSubMatrix(mat, n) << endl;
}
void test2(){
    int n = 2;
    vector<vector<int> > mat(n, vector<int>(n, 0));
    int a[] = {-10,1,-15,24};
    for(int i = 0; i < n*n; ++i){
        mat[i/n][i%n] = a[i];
    }
    cout << "ok" << endl;
    cout <<  SubMatrix().sumOfSubMatrix(mat, n) << endl;
}
int main(){
    //test1();
    test2();
    return 0;
}
