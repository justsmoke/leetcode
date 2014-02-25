//Given an encoded message containing digits, determine the total number of ways to decode it.

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		int l = s.length();
		if (!l || s[0] == '0') {
			return 0;
		}
		int x = 1, y = 1, t;
		for (int i = 1; i != l; ++ i) {
			t = x;
			x = y;
			y = 0;
			if (s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7')) {
				y += t;
			}
			if (s[i] != '0') {
				y += x;
			}
			if (y == 0) {
				return 0;
			}
		}
		return y;
	}
};

int main() {
	Solution sol = Solution();
	cout << sol.numDecodings("1270192301348324") << endl;
	return 0;
}
