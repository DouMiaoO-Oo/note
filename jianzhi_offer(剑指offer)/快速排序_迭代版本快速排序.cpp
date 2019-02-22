#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// ref1: https://blog.csdn.net/pkuyjxu/article/details/6918295
// ref2: https://www.cnblogs.com/crystalmoore/p/5930298.html
void quick_sort(vector<int>& arr){
    int n = arr.size();
    if(n <= 1) return;
    queue<pair<int, int> > q;  // start & end
    q.push(make_pair(0, n-1));  // 队列/BFS 先进先出处理每个区间
	int s, e, last_small;
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		s = p.first, e = p.second, last_small = s;
		if(s >= e) continue;  // at least 2 elements
		for(int i = s+1; i <= e; ++i){
			if(arr[s] > arr[i]) swap(arr[++last_small], arr[i]);
		} swap(arr[s], arr[last_small]);  // pivot position is last_small
		q.push(make_pair(s, last_small-1));
		q.push(make_pair(last_small+1, e));
	}
}
void print(vector<int> v){
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << ' ';
    } cout << endl;
}
void check(vector<int> arr, void (*f)(vector<int>&) ){
    vector<int> sorted_arr(arr.begin(), arr.end());
    sort(sorted_arr.begin(), sorted_arr.end());
    vector<int> v(arr.begin(), arr.end());
    f(v);
    if(sorted_arr.size() != v.size()){
        cout << "sort failed: the element number is changed." << endl;
        return;
    }
    for(int i = 1; i < v.size(); ++i){
        if(v[i-1] > v[i]){
            cout << "sort failed: not ordered." << endl;
            return;
        }
    }
    for(int i = 0; i < v.size(); ++i){
        if(sorted_arr[i] != v[i]){
            cout << "sort failed: element is change." << endl;
            return;
        }
    }
    cout << "sort succeed" << endl;

}
void test(){
    int T = 100;
    while(T--){
        int n = 100, a[100];
        for(int i = 0; i < n; ++i) a[i] = rand();
        vector<int> v(a, a+n);
        check(v, quick_sort);
    }
    return;
}
int main(){
    test();
    return 0;
}
