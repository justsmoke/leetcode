//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//Each element in the array represents your maximum jump length at that position.
//Your goal is to reach the last index in the minimum number of jumps.

#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
	int jump(int A[], int n) {
		if (n == 1) {
			return 0;
		}
		int step = 1, cursor = 0, max = A[0], prev, t;
		while (max < n - 1) {
			prev = max;
			while (max < n - 1 && cursor <= prev) {
				t = A[cursor] + cursor;
				max = t > max ? t : max;
				++ cursor;
			}
			++ step;
		}
		return step;
	}
};

int main() {
	Solution sol = Solution();
	int A[] = {1,1,1,1,1,1,1,1,1,3};
	cout << sol.jump(A, 10) << endl;
	return 0;
}
