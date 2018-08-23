#include <iostream>
#include<vector>
using namespace std;
int partition(vector<int>& a, int l, int r)
{
    // assert l < r
    int p = a[l];  // pivot
    int i=l+1, j=r;
    int cnt = 0;
    while(i < j){
        cout << "cnt = " << cnt++ << endl;
        while(a[i] <= p && i<j){
            // 终止于 a[i]>p 或者 (i==j) 时
            ++i;
        }
        while(p < a[j] && i<j){
            // 终止于 a[j]<=p 或者 (j==i) 时
            --j;
        }
        //cout << "i=" << i << " j= " << j << endl;
        if(i<j) {  // // 这句不能少
            // i = j-1时还会进入这个循环
            swap(a[i++], a[j--]); // 这一句估计会出错?
            /* 循环结束时, 可能发生
                i < j, e.g. i=10 &&j=20 进入该循环
                i == j, e.g. 1=1&&j=3进入该循环
                i > j, e.g. 1=1&&j=2进入该循环
            */
        }
        //cout << "\ti=" << i << " j= " << j << endl;
    }  /*
        这个`while(i<j)`结束时， 可能是 i==j 或者 i>j
    */

    swap(a[i], a[l]);  // 结论：这一句写错了
    return i;   // 结论：这一句写错了
}
void quick_sort(vector<int>& a, int l, int r, int k)
{
    if(a.size() > 1)
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
    int a[] = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> res = GetLeastNumbers_Solution(vector<int>(a, a+8), 4);
    for(int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}
