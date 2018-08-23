#include <iostream>
#include<vector>
#include<assert.h>    // 牛客网在类外面补充一个头文件就可以使用断言了
/*
这个代码已经通过，debug的过程比较有成就感
*/
using namespace std;
int partition(vector<int>& a, int l, int r)
{  // 此代码已经通过
    assert(l < r);
    int p = a[l];  // pivot
    int i=l+1, j=r;
    while(i < j){
        while(a[i] <= p && i<j){
            // 终止于 a[i]>p 或者 (i==j) 时
            ++i;
        }
        while(p < a[j] && i<j){
            // 终止于 a[j]<=p 或者 (j==i) 时
            --j;
        }
        //cout << "i=" << i << " j= " << j << endl;
        if(i<j)  // 这句不能少
            swap(a[i++], a[j--]);
        //cout << "\ti=" << i << " j= " << j << endl;
    }
    assert(i == j  || i-1==j);
    swap(a[j], a[l]);  // 修改的语句
    return j;  // 修改的语句
}
void quick_sort(vector<int>& a, int l, int r, int k)
{
    if(l < r)
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
    if(input.size() < k) return input;
    if(input.size() == 0 || k<=0) return vector<int>();
    quick_sort(input, 0, input.size()-1, k);
    return vector<int>(&input[0], &input[k]);
}
int main()
{
    int a[] = {4, 5, 1, 6, 2, 7, 3, 8}; int k = 4; int len = 8;
    //int a[] = {4,5,1,6,2,7,2,8}; int k = 2; int len = 8;
    vector<int> res = GetLeastNumbers_Solution(vector<int>(a, a+len), k);
    for(int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}
