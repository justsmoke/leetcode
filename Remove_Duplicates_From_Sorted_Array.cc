//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice?

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (sizeof(A) == 0 || n == 0) {
			return 0;
		}
		int pos = 0, i = 0;
		int last = A[0];
		for (int i = 0; i < n; ++ i) {
			if (A[i] != last) {
				A[pos++] = last;
				last = A[i];
			}
		}
		A[pos++] = last;
		return pos;
	}
};

int main() {
	Solution sol = Solution();
	int A[] = {1, 2, 2};
	int m = sol.removeDuplicates(A, 3);
	cout << m << endl;
	for (int i = 0; i != m; ++ i) {
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}
