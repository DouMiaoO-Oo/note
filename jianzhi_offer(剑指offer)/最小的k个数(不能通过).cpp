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
            // ��ֹ�� a[i]>p ���� (i==j) ʱ
            ++i;
        }
        while(p < a[j] && i<j){
            // ��ֹ�� a[j]<=p ���� (j==i) ʱ
            --j;
        }
        //cout << "i=" << i << " j= " << j << endl;
        if(i<j) {  // // ��䲻����
            // i = j-1ʱ����������ѭ��
            swap(a[i++], a[j--]); // ��һ����ƻ����?
            /* ѭ������ʱ, ���ܷ���
                i < j, e.g. i=10 &&j=20 �����ѭ��
                i == j, e.g. 1=1&&j=3�����ѭ��
                i > j, e.g. 1=1&&j=2�����ѭ��
            */
        }
        //cout << "\ti=" << i << " j= " << j << endl;
    }  /*
        ���`while(i<j)`����ʱ�� ������ i==j ���� i>j
    */

    swap(a[i], a[l]);  // ���ۣ���һ��д����
    return i;   // ���ۣ���һ��д����
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
