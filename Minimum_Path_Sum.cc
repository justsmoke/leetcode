//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//Note: You can only move either down or right at any point in time.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		if (grid.size() == 0 || grid[0].size() == 0) {
			return 0;
		}
		int row = grid.size(), col = grid[0].size();
		int t;
		for (int i = 0; i != row; ++ i) {
			for (int j = 0; j != col; ++ j) {
				if (i == 0 && j == 0) {
					t = 0;
				} else if (i == 0) {
					t = grid[i][j - 1];
				} else if (j == 0) {
					t = grid[i - 1][j];
				} else {
					t = min(grid[i][j - 1], grid[i - 1][j]);
				}
				grid[i][j] += t;
			}
		}
		return grid[row - 1][col - 1];
	}
};

int main() {
	Solution sol = Solution();
	return 0;
}
