//Given a string S and a string T, count the number of distinct subsequences of T in S.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int numDistinct(string S, string T) {
		int m = S.length(), n = T.length();
		if (m < n || n == 0) {
			return 0;
		}
		vector<vector<int>> ans(n, vector<int>(m, 0));
		vector<int> first;
		int c = 0;
		for (int i = 0; i != m; ++ i) {
			if (S[i] == T[0]) {
				++ c;
			}
			first.push_back(c);
		}
		ans[0].assign(first.begin(), first.end());
		for (int i = 1; i != n; ++ i) {
			for (int j = i; j != m; ++ j) {
				if (T[i] == S[j]) {
					ans[i][j] += ans[i-1][j-1];
				}
				if (j > i) {
					ans[i][j] += ans[i][j-1];
				}
			}
		}
		return ans[n-1][m-1];
	}
};

int main() {
	Solution sol = Solution();
	string S, T;
	cin >> S;
	cin >> T;
	cout << sol.numDistinct(S, T) << endl;
	return 0;
}
