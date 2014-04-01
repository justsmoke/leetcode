//A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//How many possible unique paths are there?

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m == 0 || n == 0) {
			return 0;
		}
		if (m > n) {
			int t = m;
			m = n;
			n = t;
		}
		-- m;
		-- n;
		int ret = 1;
		for (int i = 1; i <= m; ++ i) {
			int q = ret/i, r = ret%i;
			ret = q*(n+i) + r*(n+i)/i;
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	int m, n;
	cin >> m >> n;
	cout << sol.uniquePaths(m, n) << endl;
	return 0;
}
