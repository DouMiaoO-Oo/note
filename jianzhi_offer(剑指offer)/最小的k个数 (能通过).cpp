#include <iostream>
#include<vector>
using namespace std;
int partition(vector<int>& a, int l, int r)
{
    int p = a[l];  // pivot
    int i=l, j = r;
    while(i < j){
        while(p < a[j] && i<j){
            // 终止于 a[j]<=p 或者 (j==i) 时
            --j;
        }
        a[i] = a[j];
        while(a[i] <= p && i<j){
            // 终止于 a[i]>p 或者 (i==j) 时
            ++i;
        }
        a[j] = a[i];
    }
    a[i] = p;
    return i;
}
void quick_sort(vector<int>& a, int l, int r, int k)
{
    if(a.size() > 1)  // 这里最好修改 l < r
    {
        int pivot = partition(a, l, r);
        if(pivot == k-1)
        {
            return;
        }
        else if(pivot < k-1)
        {
            quick_sort(a, pivot+1, r, k);
        }
        else
        {
            quick_sort(a, l, pivot-1, k);
        }
    }
}
vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
    // assert k > 0 && k <= input.size()
    if(input.size() < k) return vector<int>();
    //if(input.size() < k) return input;
    if(input.size() == 0 || k<=0) return vector<int>();
    quick_sort(input, 0, input.size()-1, k);
    return vector<int>(&input[0], &input[k]);
}
/*
// 方法二，part函数有所不同
class Solution {
public:
    int part(vector<int>& a, int l, int r){
        int p = l; // pivot position
        for(int i = l+1; i <= r; ++i){
            if(a[l] >= a[i])
                swap(a[++p], a[i]);
        } swap(a[l], a[p]);
        return p;
    }
    void helper(vector<int>& arr, int l, int r, int k){
        if(l < r){
            int pivot = part(arr, l, r);
            if(pivot == k-1) return;
            if(pivot < k-1) helper(arr, pivot+1, r, k);
            else helper(arr, l, pivot-1, k);
        } return;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k <= 0 || input.size() < k) return vector<int>();
        helper(input, 0, input.size()-1, k);
        return vector<int>(&input[0], &input[k]);
    }
};
*/

int main()
{
    int a[] = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> res = GetLeastNumbers_Solution(vector<int>(a, a+8), 4);
    for(int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}
