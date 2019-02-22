#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
struct Node{  // 可以用pair<int, int>
  int r, c;
  Node(int x, int y): r(x), c(y){}
};
class Solution {
public:
    int const h[4] = {0, 0, 1, -1};  // 这个的声明容易错
    int const v[4] = {1, -1, 0, 0};
    int get_sum(int n){
        int sum = 0;
        while(n!=0){
            sum += n%10;
            n /= 10;
        } return sum;
    }
    bool is_valid(int r, int c,
                 int k, int m, int n){
        if(r<0 || c<0) return false;
        if(r>=m || c>= n) return false;
        return (get_sum(r)+get_sum(c)) <= k;
    }
    int movingCount(int threshold, int row, int col)
    {
        if(threshold <= 0 || row <= 0 || col <= 0 ) return 0;
        vector<vector<bool> > flag;
        for(int i = 0; i < row; ++i){
            flag.push_back(vector<bool>(col, false));
        }
        queue<Node> q;
        q.push(Node(0, 0));
        flag[0][0] = true; // 容易遗漏
        int cnt = 1;
        while(!q.empty()){
            Node node = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i){
                int r = node.r+v[i];
                int c = node.c+h[i];
                if(is_valid(r, c, threshold, row, col) && !flag[r][c]){
                    flag[r][c] = true;
                    q.push(Node(r, c));
                    ++cnt;
                }
            }
        } return cnt;
    }
};
int main(){
	cout << "cnt is " << Solution().movingCount(5, 10, 10) << endl;
    return 0;
}
