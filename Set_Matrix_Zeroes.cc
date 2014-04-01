//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.  
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>> &matrix) {
		int m = matrix.size();
		if (m == 0) {
			return;
		}
		int n = matrix[0].size();
		if (n == 0) {
			return;
		}
		bool firstZero = true;
		int hasZeroRow = -1, hasZeroCol = -1;
		for (int i = 0; i != m; ++ i) {
			for (int j = 0; j != n; ++ j) {
				if (matrix[i][j] == 0) {
					if (firstZero) {
						hasZeroRow = i;
						hasZeroCol = j;
						firstZero = false;
					} else {
						matrix[hasZeroRow][j] = 0;
						matrix[i][hasZeroCol] = 0;
					}
				}
			}
		}
		if (!firstZero) {
			for (int i = 0; i != m; ++ i) {
				if (i != hasZeroRow && matrix[i][hasZeroCol] == 0) {
					for (int j = 0; j != n; ++ j) {
						matrix[i][j] = 0;
					}
				}
				matrix[i][hasZeroCol] = 0;
			}
			for (int j = 0; j != n; ++ j) {
				if (j != hasZeroCol && matrix[hasZeroRow][j] == 0) {
					for (int i = 0; i != m; ++ i) {
						matrix[i][j] = 0;
					}
				}
				matrix[hasZeroRow][j] = 0;
			}
		}
	}
};

int main() {
	Solution sol = Solution();
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	vector<int> u;
	u.push_back(1);
	u.push_back(0);
	u.push_back(1);
	vector<vector<int>> matrix;
	matrix.push_back(u);
	matrix.push_back(v);
	sol.setZeroes(matrix);
	for (int i = 0; i != 2; ++ i) {
		for (int j = 0; j != 3; ++ j) {
			if (matrix[i][j] != 0) {
				cout << i << "#" << j << endl;
			}
		}
	}
	return 0;
}
