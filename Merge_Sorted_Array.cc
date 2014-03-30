//Given two sorted integer arrays A and B, merge B into A as one sorted array.
//You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int i = m - 1, j = n - 1, p = m + n - 1;
		while (i >= 0 && j >= 0) {
			if (A[i] >= B[j]) {
				A[p--] = A[i--];
			} else {
				A[p--] = B[j--];
			}
		}
		while (j >= 0) {
			A[j] = B[j];
			-- j;
		}
	}
};

int main() {
	Solution sol = Solution();
	int A[] = {1, 2, 3, 4, 10};
	int B[] = {5, 6, 7};
	int m = 0, n = 2;
	sol.merge(A, m, B, n);
	for (int i = 0; i != m + n; ++ i) {
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}
