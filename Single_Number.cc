//Given an array of integers, every element appears twice except for one. Find that single one.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int singleNumber(int A[], int n) {
		int ret = 0;
		for (int i = 0; i != n; ++ i) {
			ret ^= A[i];
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	int A[5] = {1,2,3,2,1};
	cout << sol.singleNumber(A, 5);
	return 0;
}
