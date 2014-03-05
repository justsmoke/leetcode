//Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		int i = 0;
		while (i < n) {
			if (A[i] < target) {
				++ i;
			} else {
				return i;
			}
		}
		return n;
	}
};

int main() {
	Solution sol = Solution();
	return 0;
}
