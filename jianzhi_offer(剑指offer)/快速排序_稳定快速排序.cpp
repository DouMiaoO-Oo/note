#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*  // https://www.geeksforgeeks.org/stable-quicksort/
# Python code to implement Stable QuickSort.
# The code uses middle element as pivot.
def quickSort(ar):

	# Base case
	if len(ar) <= 1:
		return ar

	# Let us choose middle element a pivot
	else:
		mid = len(ar)//2
		pivot = ar[mid]

		# key element is used to break the array
		# into 2 halves according to their values
		smaller,greater = [],[]

		# Put greater elements in greater list,
		# smaller elements in smaller list. Also,
		# compare positions to decide where to put.
		for indx, val in enumerate(ar):
			if indx != mid:
				if val < pivot:
					smaller.append(val)
				elif val > pivot:
					greater.append(val)

				# If value is same, then considering
				# position to decide the list.
				else:
					if i < mid:
						smaller.append(val)
					else:
						greater.append(val)
		return quickSort(smaller)+[pivot]+quickSort(greater)

# Driver code to test above
ar = [10, 7, 8, 9, 1, 5]
sortedAr = quickSort(ar)
print(sortedAr)
*/
// ref: https://github.com/RodneyShag/HackerRank_solutions/blob/master/Algorithms/Sorting/Quicksort%202%20-%20Sorting/Solution.java
int stable_partition(vector<int>& arr, int s, int e) {
    if (s >= e) return s;
    vector<int> left, right;
    for(int i = s+1; i <= e; ++i){
        if(arr[i] < arr[s]) left.push_back(arr[i]);
        else right.push_back(arr[i]);
    }  int pivot_position = s+left.size();
    arr[pivot_position] = arr[s];  // pivot
    for(int i = 0, j = s; i < left.size(); ++i, ++j) arr[j] = left[i];
    for(int i = 0, j = pivot_position+1; i < right.size(); ++i, j++) arr[j] = right[i];
    return pivot_position;
}

void quick_sort(vector<int>& arr, int l, int r){
    // assert(arr.size() > 1);
    if(l >= r) return;
    int pivot = stable_partition(arr, l, r);
    quick_sort(arr, l, pivot-1);
    quick_sort(arr, pivot+1, r);
}

void check(vector<int> arr, void (*f)(vector<int>&, int, int) ){
    vector<int> sorted_arr(arr.begin(), arr.end());
    sort(sorted_arr.begin(), sorted_arr.end());
    vector<int> v(arr.begin(), arr.end());
    f(v, 0, v.size()-1);
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
