#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
/*
	��Ŀ��
		��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
		����һ���Ǽ�����������һ����ת�������ת�������СԪ�ء�
		��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
		NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��

	��Ϊ��ȷ����������һ����������ת���������Ƕ��ֵ�Ŀ������ҵ����ڵ����������������������ǽ���ġ�
    Ҫ�����ڵ������������Զ��ֵ���ֹ�����͵��� left+1 < right

	����Ľⷨ������� https://www.nowcoder.com/questionTerminal/9f3231a991af4f55b95579b44b7a01ba?toCommentId=1259695
	    int minNumberInRotateArray(vector<int> v) {
			if(v.empty()) return 0;
			int l = 0, r = v.size()-1;
			while(l+1 < r){
				int mid = (l+r)/2;
				if(v[l] > v[mid]){
					r = mid;
				} else{
					l = mid;
				}
			} return v[r];
		}
	��Ҫ���ǵ����������
	�� ������ת���ֵĳ��� len s.t. (len%v.size()) == 0
	�� ���ԭ����Ϊ011111����ת������Ϊ101111����������Ͳ���ͨ���ˡ�
	���Ե�v[l]=v[mid]ʱ������Ƚ����⣬ֻ���޸��±��һ���ж���һ��Ԫ�أ��������ܰ��±�ĳ�mid��
		//* ����������� /
         1
         2 1
         5 6 1
         6 1 2
         4 5 6 1 2 3
         1 2   // is OK?
		 1, 0, 1, 1, 1, 1  // ����Ĵ�����벻��ͨ��������


*/
class Solution {
public:
	int minNumberInRotateArray(vector<int> v) {
        if(v.empty()) return 0;  // ����������Ԫ�ض�����0���������СΪ0���뷵��0��
        int l = 0, r = v.size()-1;
        if(v[l] < v[r]) return v[l]; // ��������ת����������ԭ��������һ��
        while(l+1 < r){
            int mid = (l+r)/2;
            if(v[l] == v[mid] && v[mid] == v[r]){
                // ˳���������Сֵ
                int res = v[l];
                for(int i = l+1; i<=r; ++i)
                    if(v[i]<res)
                        res = v[i];
                return res;
            }
            if(v[l] > v[mid]){
                r = mid;
            } else{ // if(v[l] <= v[mid]){ // ����ķ�������Ҫ��v[l] < v[mid]ʱ�����׷�������v[l] == v[mid]ʱ����Ϊv[mid]��v[r]����ȣ����һ������v[mid]>v[r]
                l = mid;
            } 
            
        } return v[r];
    }
};
int main(){
	int a[] = {1, 0, 1, 1, 1, 1};
	int res = Solution().minNumberInRotateArray(vector<int>(a, a+6));
	cout << res << endl;
    return 0;
}
