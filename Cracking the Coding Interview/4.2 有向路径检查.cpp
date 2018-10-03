#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <sstream>
#include <cmath>
#include <unordered_set>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<struct UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};

class Path {
public:
    bool helper(UndirectedGraphNode* a, UndirectedGraphNode* b){
        queue<UndirectedGraphNode* > q;
        unordered_set<UndirectedGraphNode* > s;
        q.push(a);
        s.insert(a);
        while(!q.empty()){
            UndirectedGraphNode* t = q.front();
            if(t == b) return true;
            q.pop();
            for(int i = 0; i < t->neighbors.size(); ++i){
                if(t->neighbors[i] && s.find(t->neighbors[i]) == s.end()){
                    q.push(t->neighbors[i]);
                    s.insert(t->neighbors[i]);
                }
            }
        } return false;
    }
    bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        if(a == NULL || b == NULL) return false;
        return helper(a, b) || helper(b, a);
    }
};
int main(){

    return 0;
}
