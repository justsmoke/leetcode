//Given an unsorted integer array, find the first missing positive integer.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		for (int i = 0; i != n; ++ i) {
			int j = i, k = A[i], t;
			while (1) {
				if (k <= 0 || k > n || k == j+1) {
					break;
				}
				j = k - 1;
				t = A[k-1];
				A[k-1] = k;
				k = t;
			}
		}
		for (int i = 0; i != n; ++ i) {
			if (A[i] != i + 1) {
				return i + 1;
			}
		}
		return n + 1;
	}
};

int main() {
	Solution sol = Solution();
	int A[] = {2,1}, n = 2;
	cout << sol.firstMissingPositive(A, n) << endl;
	return 0;
}
