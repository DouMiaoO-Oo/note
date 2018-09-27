#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        int len = board.size();
        for(int i = 0; i < len; ++i){
            if(board[i][0] + board[i][1] + board[i][2] == 3) return true;
            if(board[0][i] + board[1][i] + board[2][i] == 3) return true;
        }
        if(board[0][0] + board[1][1] + board[2][2] == 3) return true;
        if(board[2][0] + board[1][1] + board[0][2] == 3) return true;
        return false;
    }
};
int main(){

    return 0;
}
