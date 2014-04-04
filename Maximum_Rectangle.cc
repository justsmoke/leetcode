//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		int m = matrix.size();
		if (m == 0) {
			return 0;
		}
		int n = matrix.back().size();
		if (n == 0) {
			return 0;
		}
		vector<int> row(n, 0);
		int max = 0, tmp;
		for (auto i = matrix.begin(); i != matrix.end(); ++ i) {
			vector<char> v = *i;
			for (int j = 0; j != n; ++ j) {
				if (v[j] == '1') {
					row[j] += v[j] - '0';
				} else {
					row[j] = 0;
				}
			}
			tmp = getMax(row, n);
			max = tmp > max ? tmp : max;
		}
		return max;
	}

	int getMax(vector<int> row, int n) {
		stack<int> s;
		int max = 0, tmp, i = 0;
		while (i < n) {
			if (s.empty() || row[s.top()] <= row[i]) {
				s.push(i);
				++ i;
			} else {
				tmp = s.top();
				s.pop();
				tmp = row[tmp] * (s.empty() ? i : i - s.top() - 1);
				max = tmp > max ? tmp : max;
			}
		}
		while (!s.empty()) {
			tmp = s.top();
			s.pop();
			tmp = row[tmp] * (s.empty() ? i : i - s.top() - 1);
			max = tmp > max ? tmp : max;
		}
		return max;
	}
};

int main() {
	Solution sol = Solution();
	int n;
	cin >> n;
	vector<vector<char>> matrix;
	for (int i = 0; i != n; ++ i) {
		vector<char> v;
		int t;
		for (int j = 0; j != n; ++ j) {
			cin >> t;
			v.push_back('0' + t);
		}
		matrix.push_back(v);
	}
	cout << sol.maximalRectangle(matrix) << endl;
	return 0;
}
