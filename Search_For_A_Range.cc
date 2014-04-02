//Given a sorted array of integers, find the starting and ending position of a given target value.
//If the target is not found in the array, return [-1, -1].

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		int left = 0, right = n-1, mid;
		int hit = -1;
		while (left <= right && left >= 0 && right <= n-1) {
			mid = (left+right)/2;
			if (A[mid] == target) {
				hit = mid;
				break;
			} else if (A[mid] < target) {
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		if (hit == -1) {
			return vector<int>(2, -1);
		}
		int start = hit, end = hit;
		while (left < start) {
			mid = (left+start)/2;
			if (A[mid] == target) {
				start = mid;
			} else {
				left = mid + 1;
			}
		}
		while (end < right) {
			mid = (end+right+1)/2;
			if (A[mid] == target) {
				end = mid;
			} else {
				right = mid-1;
			}
		}
		vector<int> ret;
		ret.push_back(start);
		ret.push_back(end);
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	int A[] = {5,7,7,8,8,8,10};
	auto v = sol.searchRange(A, 1, 5);
	cout << v[0] << "#" << v[1] << endl;
	return 0;
}
