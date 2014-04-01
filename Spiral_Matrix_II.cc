//Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		int m = 0, p = 1;
		vector<vector<int>> ret(n, vector<int>(n));
		while (m < n/2) {
			for (int i = m; i != n-m-1; ++ i) {
				ret[m][i] = p++;
			}
			for (int i = m; i != n-m-1; ++ i) {
				ret[i][n-m-1] = p++;
			}
			for (int i = n-m-1; i != m; -- i) {
				ret[n-m-1][i] = p++;
			}
			for (int i = n-m-1; i != m; -- i) {
				ret[i][m] = p++;
			}
			++ m;
		}
		if (n%2 == 1) {
			ret[n/2][n/2] = p++;
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	int n;
	cin >> n;
	auto ret = sol.generateMatrix(n);
	for (int i = 0; i != n; ++ i) {
		for (int j = 0; j != n; ++ j) {
			cout << ret[i][j] << "#";
		}
		cout << endl;
	}
	return 0;
}
