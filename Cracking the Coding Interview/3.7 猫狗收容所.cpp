#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
class CatDogAsylum {
public:
    /*第一个压入ID， 第二个压入动物的编号 
    这种实现会有bug，在动物不断增多的情况下，int 可能会溢出
    */
    vector<int> asylum(vector<vector<int> > op) {
        queue<int> dog, cat;
        int id = 0;
        vector<int> res;
        for(int i = 0; i < op.size(); ++i){
            if(op[i][0] == 1){
                if(op[i][1] > 0){
                  dog.push(id++);
                  dog.push(op[i][1]);  
                } else{
                    cat.push(id++);
                    cat.push(op[i][1]);
                }
            } else{ // op[i][0] == 2
                int flag = 0;
                if(op[i][1] == 0){
                    if(dog.empty() && cat.empty()) continue;
                    else if(!dog.empty() && cat.empty()) flag = 1;
                    else if(dog.empty() && !cat.empty()) flag = -1;
                    else{
                        if(dog.front()<cat.front()) flag = 1;
                        else flag = -1;
                    }
                } else if(op[i][1] == 1){
                    if(dog.empty()) continue;
                    flag = 1;
                } else{  // op[i][1] == -1
                    if(cat.empty()) continue;
                    flag = -1;
                }
                queue<int> *animal = NULL;
                if(flag == 1) animal = &dog;
                else animal = &cat;
                (*animal).pop();
                res.push_back((*animal).front());
                (*animal).pop();
            }
        } return res;
    }
};
int main(){

    return 0;
}
