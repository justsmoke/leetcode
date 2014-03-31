//The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//Given an integer n, return all distinct solutions to the n-queens puzzle.
//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<int>> ans;
		vector<vector<string>> ret;
		for (int i = 0; i != n; ++ i) {
			solve(1, n, vector<int>(1, i), ans);
		}
		for (int i = 0; i != ans.size(); ++ i) {
			vector<string> one;
			for (int j = 0; j != n; ++ j) {
				string s(n, '.');
				s[ans[i][j]] = 'Q';
				one.push_back(s);
			}
			ret.push_back(one);
		}
		return ret;
	}
	void solve(int row, int n, vector<int> queen, vector<vector<int>> &ans) {
		if (row == n) {
			ans.push_back(queen);
		} else {
			for (int i = 0; i != n; ++ i) {
				bool ok = true;
				for (int j = 0; j != row; ++ j) {
					if ((i == queen[j]) || (i == queen[j] + j - row) || (i == queen[j] + row - j)) {
						ok = false;
						continue;
					}
				}
				if (ok) {
					vector<int> q(queen);
					q.push_back(i);
					solve(row + 1, n, q, ans);
				}
			}
		}
	}
};

int main() {
	Solution sol = Solution();
	int n;
	cin >> n;
	auto ret = sol.solveNQueens(n);
	for (int i = 0; i != ret.size(); ++ i) {
		for (int j = 0; j != n; ++ j) {
			cout << ret[i][j] << endl;
		}
		cout << endl;
	}
	return 0;
}
