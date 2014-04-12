//Divide two integers without using multiplication, division and mod operator.

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0) {
			return 0;
		}
		bool negative = false;
		unsigned int diva, divb;
		if (dividend < 0 && divisor > 0) {
			negative = true;
		} else if (dividend > 0 && divisor < 0) {
			negative = true;
		}
		diva = dividend > 0 ? dividend : - dividend;
		divb = divisor > 0 ? divisor : - divisor;
		int ans = 0;
		while ((diva >> 1) >= divb) {
			int q = 0;
			while ((diva >> 1) >= (divb << q)) {
				q += 1;
			}
			ans += 1 << q;
			diva -= divb << q;
		}
		if (diva >= divb) {
			++ ans;
		}
		return negative ? - ans : ans;
	}
};

int main() {
	Solution sol = Solution();
	int n, m;
	cin >> n >> m;
	cout << sol.divide(n, m) << endl;
	return 0;
}
