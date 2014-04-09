//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//Each element in the array represents your maximum jump length at that position.
//Determine if you are able to reach the last index.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	bool canJump(int A[], int n) {
		int max = 0;
		for (int i = 0; i != n; ++ i) {
			if (max < i) {
				return false;
			}
			if (i + A[i] > max) {
				max = i + A[i];
			}
			if (max > n - 1) {
				return true;
			}
		}
	}
};

int main() {
	Solution sol = Solution();
	int A[] = {3,2,1,0,4};
	if (sol.canJump(A, 5)) {
		cout << "YES!" << endl;
	}
	return 0;
}
