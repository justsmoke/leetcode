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
		if (word.length() == 0) {
			return true;
		}
		int m = board.size();
		if (m == 0) {
			return false;
		}
		int n = board[0].size();
		if (n == 0) {
			return false;
		}
		//Up : 0, Down : 1, Left : 2, Right : 3
		vector<vector<vector<int>>> way(m * n, vector<vector<int>>(word.length(), vector<int>(4, 0)));
		unordered_map<string, vector<int>> step;
		vector<bool> visited(m * n, false);
		stack<int> path;
		string s("00");
		for (int i = 0; i != word.length() - 1; ++ i) {
			step[word.substr(i, 2)].push_back(i);
		}
		for (int k = 0; k != m * n; ++ k) {
			int i = k / n;
			int j = k % n;
			s[0] = board[i][j];
			vector<pair<string, int>> edge;
			if (i != 0) {
				s[1] = board[i - 1][j];
				edge.push_back(make_pair(s, 0));
			}
			if (i != m - 1) {
				s[1] = board[i + 1][j];
				edge.push_back(make_pair(s, 1));
			}
			if (j != 0) {
				s[1] = board[i][j - 1];
				edge.push_back(make_pair(s, 2));
			}
			if (j != n - 1) {
				s[1] = board[i][j + 1];
				edge.push_back(make_pair(s, 3));
			}
			for (auto u = edge.begin(); u != edge.end(); ++ u) {
				for (auto it = step[u->first].begin(); it != step[u->first].end(); ++ it) {
					way[k][*it][u->second] = 1;
				}
			}
		}
		int start = 0, pos = 0, last;
		while (start != m * n) {
			for (; start != m * n; ++ start) {
				if (board[start / n][start % n] == word[0]) {
					break;
				}
			}
			if (start == m * n) {
				break;
			}
			visited[start] = true;
			path.push(start);
			pos = 1;
			while (!path.empty() && pos != word.length()) {
				last = path.top();
				if (way[last][pos - 1][0] && !visited[last - n]) {
					way[last][pos - 1][0] = 0;
					++ pos;
					visited[last - n] = true;
					path.push(last - n);
					continue;
				}
				if (way[last][pos - 1][1] && !visited[last + n]) {
					way[last][pos - 1][1] = 0;
					++ pos;
					visited[last + n] = true;
					path.push(last + n);
					continue;
				}
				if (way[last][pos - 1][2] && !visited[last - 1]) {
					way[last][pos - 1][2] = 0;
					++ pos;
					visited[last - 1] = true;
					path.push(last - 1);
					continue;
				}
				if (way[last][pos - 1][3] && !visited[last + 1]) {
					way[last][pos - 1][3] = 0;
					++ pos;
					visited[last + 1] = true;
					path.push(last + 1);
					continue;
				}
				path.pop();
				-- pos;
				visited[last] = false;
			}
			if (pos == word.length()) {
				return true;
			}
			++ start;
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
