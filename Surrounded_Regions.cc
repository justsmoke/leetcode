//Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
//A region is captured by flipping all 'O's into 'X's in that surrounded region .

#include <vector>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
	void solve(vector<vector<char> > &board) {
		if (!board.size() || !board[0].size()) {
			return;
		}
		int n = board.size();
		int m = board[0].size();
		queue<pair<int, int> > notSurrounded;
		for (int i = 0; i != m; ++ i) {
			if (board[0][i] == 'O') {
				board[0][i] = '#';
				notSurrounded.push(make_pair(0, i));
			}
			if (board[n-1][i] == 'O') {
				board[n-1][i] = '#';
				notSurrounded.push(make_pair(n-1, i));
			}
		}
		for (int i = 0; i != n; ++ i) {
			if (board[i][0] == 'O') {
				board[i][0] = '#';
				notSurrounded.push(make_pair(i, 0));
			}
			if (board[i][m-1] == 'O') {
				board[i][m-1] = '#';
				notSurrounded.push(make_pair(i, m-1));
			}
		}
		while (notSurrounded.size()) {
			pair<int, int> node = notSurrounded.front();
			notSurrounded.pop();
			int x = node.first, y = node.second;
			if (x-1 > 0 && board[x-1][y] == 'O') {
				board[x-1][y] = '#';
				notSurrounded.push(make_pair(x-1, y));
			}
			if (x+1 < n && board[x+1][y] == 'O') {
				board[x+1][y] = '#';
				notSurrounded.push(make_pair(x+1, y));
			}
			if (y-1 > 0 && board[x][y-1] == 'O') {
				board[x][y-1] = '#';
				notSurrounded.push(make_pair(x, y-1));
			}
			if (y+1 < m && board[x][y+1] == 'O') {
				board[x][y+1] = '#';
				notSurrounded.push(make_pair(x, y+1));
			}
		}
		for (int i = 0; i != n; ++ i) {
			for (int j = 0; j != m; ++ j) {
				board[i][j] = (board[i][j] == '#' ? 'O' : 'X');
			}
		}
	}
};

int main() {
	Solution sol = Solution();
	vector<vector<char> > board(4, vector<char>(6, 'X'));
	for (int i = 0; i < 4; i += 2) {
		for (int j = 1; j < 6; j += 2) {
			board[i][j] = 'O';
		}
	}
	for (int i = 1; i < 4; i += 2) {
		for (int j = 0; j < 6; j += 2) {
			board[i][j] = 'O';
		}
	}
	for (int i = 0; i < 4; ++ i) {
		for (int j = 0; j < 6; ++ j) {
			cout << board[i][j];
		}
		cout << endl;
	}
	sol.solve(board);
	for (int i = 0; i != 4; ++ i) {
		for (int j = 0; j != 6; ++ j) {
			cout << board[i][j];
		}
		cout << endl;
	}
	return 0;
}
