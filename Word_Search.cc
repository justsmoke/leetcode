//Given a 2D board and a word, find if the word exists in the grid.
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

#include <vector>
#include <unordered_map>
#include <utility>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		if (word == "") {
			return true;
		}
		int row = board.size();
		if (row == 0 || board[0].size() == 0) {
			return false;
		}
		int col = board[0].size();
		int start = 0, x, y, pos, last;
		while (1) {
			while (start != row * col && board[start / col][start % col] != word[0]) {
				++ start;
			}
			if (start == row * col) {
				break;
			}
			stack<pair<int, int>> dfs;
			dfs.push(make_pair(start, 0));
			vector<int> path;
			vector<bool> visited(row * col, false);
			while (!dfs.empty()) {
				pair<int, int> tp = dfs.top();
				last = tp.first;
				pos = tp.second;
				x = last / col;
				y = last % col;
				dfs.pop();
				while (path.size() > pos) {
					visited[path.back()] = false;
					path.pop_back();
				}
				path.push_back(last);
				visited[last] = true;
				++ pos;
				if (pos == word.length()) {
					return true;
				}
				if (x != 0 && board[x - 1][y] == word[pos] && !visited[last - col]) {
					dfs.push(make_pair(last - col, pos));
				}
				if (x != row - 1 && board[x + 1][y] == word[pos] && !visited[last + col]) {
					dfs.push(make_pair(last + col, pos));
				}
				if (y != 0 && board[x][y - 1] == word[pos] && !visited[last - 1]) {
					dfs.push(make_pair(last - 1, pos));
				}
				if (y != col - 1 && board[x][y + 1] == word[pos] && !visited[last + 1]) {
					dfs.push(make_pair(last + 1, pos));
				}
			}
			++ start;
		}
		return false;
	}
};

int main() {
	Solution sol = Solution();
	vector<vector<char>> board;
	string s = "ABCESFESADEE";
	int i = 0;
	vector<char> v;
	for (int row = 0; row != 3; ++ row) {
		v.clear();
		for (int col = 0; col != 4; ++ col) {
			v.push_back(s[i++]);
		}
		board.push_back(v);
	}
	cin >> s;
	if (sol.exist(board, s)) {
		cout << "YES!" << endl;
	}
	return 0;
}
