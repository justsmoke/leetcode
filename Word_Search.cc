//Given a 2D board and a word, find if the word exists in the grid.
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

#include <vector>
#include <utility>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		int m = board.size();
		if (m == 0) {
			return false;
		}
		int n = board[0].size();
		if (n == 0) {
			return false;
		}
		vector<vector<bool>> path(m, vector<bool>(n, false));
		stack<pair<int, int>> st;
		int start = 0, startX, startY, lastX, lastY, pos = 0;
		while (1) {
		}
		return false;
	}
};

int main() {
	Solution sol = Solution();
	vector<vector<char>> board;
	vector<char> v;
	v.push_back('A');
	v.push_back('B');
	v.push_back('C');
	v.push_back('E');
	board.push_back(v);
	v.clear();
	v.push_back('S');
	v.push_back('F');
	v.push_back('C');
	v.push_back('S');
	board.push_back(v);
	v.clear();
	v.push_back('A');
	v.push_back('D');
	v.push_back('E');
	v.push_back('E');
	board.push_back(v);
	string s;
	cin >> s;
	if (sol.exist(board, s)) {
		cout << "YES!" << endl;
	}
	return 0;
}
