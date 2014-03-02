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
		int count = 0, pos = 0, i = 0;
		char last = A[0];
		for (int i = 0; i < n; ++ i) {
			if (A[i] == last) {
				++ count;
			} else {
				if (count > 2) {
					count = 2;
				}
				while (count --) {
					A[pos++] = last;
				}
				last = A[i];
				count = 1;
			}
		}
		if (count > 2) {
			count = 2;
		}
		while (count --) {
			A[pos++] = last;
		}
		//A[pos] = '\0';
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
