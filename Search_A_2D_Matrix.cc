//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int row = matrix.size(), col = matrix.back().size();
		if (row == 0 || col == 0 || target < matrix[0][0] || target > matrix.back().back()) {
			return false;
		}
		int left = 0, right = row*col-1, t, mid;
		while (left < right) {
			mid = (left+right)/2;
			t = matrix[mid/col][mid%col];
			if (target == t) {
				return true;
			} else if (target > t) {
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		return matrix[left/col][left%col] == target;
	}
};

int main() {
	Solution sol = Solution();
	return 0;
}
