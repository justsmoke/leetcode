//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//You are given a target value to search. If found in the array return its index, otherwise return -1.
//You may assume no duplicate exists in the array.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int search(int A[], int n, int target) {
		if (n == 0) {
			return -1;
		}
		int left = 0, right = n - 1, mid = (left + right) / 2;
		while (left < mid) {
			if (A[left] < A[mid]) {
				left = mid;
			} else {
				right = mid;
			}
			mid = (left + right) / 2;
		}
		int pivot = left;
		if (A[left] > A[right]) {
			++ pivot;
		}
		int t = find(A, 0, pivot - 1, target);
		if (t != -1) {
			return t;
		}
		return find(A, pivot, n - 1, target);
	}
	int find(int A[], int left, int right, int target) {
		int mid;
		while (left < right) {
			mid = (left + right) / 2;
			if (target == A[mid]) {
				return mid;
			} else if (target < A[mid]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		if (target == A[left]) {
			return left;
		}
		return -1;
	}
};

int main() {
	Solution sol = Solution();
	int A[] = {4,5,6,7,8,1,2,3};
	cout << sol.search(A, 8, 8) << endl;
	return 0;
}
