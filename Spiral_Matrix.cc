//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> ret;
		if (matrix.size() == 0 || matrix[0].size() == 0) {
			return ret;
		}
		int row = matrix.size(), col = matrix[0].size();
		int i = 0, min = row < col ? row : col;
		while (i < min / 2) {
			for (int j = i; j <= col - 2 - i; ++ j) {
				ret.push_back(matrix[i][j]);
			}
			for (int j = i; j <= row - 2 - i; ++ j) {
				ret.push_back(matrix[j][col - 1 - i]);
			}
			for (int j = i; j <= col - 2 - i; ++ j) {
				ret.push_back(matrix[row - 1 - i][col - 1 - j]);
			}
			for (int j = i; j <= row - 2 - i; ++ j) {
				ret.push_back(matrix[row - 1 - j][i]);
			}
			++ i;
		}
		if (min % 2 == 1) {
			if (min == row) {
				for (int j = i; j <= col - 1 - i; ++ j) {
					ret.push_back(matrix[i][j]);
				}
			} else {
				for (int j = i; j <= row - 1 - i; ++ j) {
					ret.push_back(matrix[j][col - 1 - i]);
				}
			}
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	vector<vector<int>> matrix;
	int row, col;
	cin >> row >> col;
	int k = 0;
	for (int i = 0; i != row; ++ i) {
		vector<int> v;
		for (int j = 0; j != col; ++ j) {
			v.push_back(++k);
			cout << k << "#";
		}
		matrix.push_back(v);
		cout << endl;
	}
	vector<int> ret = sol.spiralOrder(matrix);
	for (int i = 0; i != ret.size(); ++ i) {
		cout << ret[i] << "#";
	}
	cout << endl;
	return 0;
}
