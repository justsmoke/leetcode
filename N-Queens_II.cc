//Follow up for N-Queens problem.
//Now, instead outputting board configurations, return the total number of distinct solutions.

#include <vector>
#include <iostream>

using namespace std;

//http://oj.leetcode.com/discuss/743/whats-your-solution

class Solution {
public:
	int count, limit;
	int totalNQueens(int n) {
		if (n == 0) {
			return 0;
		}
		count = 0;
		limit = (1 << n) - 1;
		bitBacktrack(0, 0, 0);
		return count;
	}
	void bitBacktrack(int col, int ld, int rd) {
		if (col == limit) {
			count += 1;
		} else {
			int ok = limit ^ (col | ld | rd), t;
			while (ok) {
				t = ok & (-ok);
				ok -= t;
				bitBacktrack(col + t, ((ld + t) << 1) & limit, (rd + t) >> 1);
			}
		}
	}
};

int main() {
	Solution sol = Solution();
	int n;
	cin >> n;
	cout << sol.totalNQueens(n) << endl;
	return 0;
}
