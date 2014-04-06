//Given two binary strings, return their sum (also a binary string).

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int m = a.length(), n = b.length();
		int max = m > n ? m : n;
		string s(max, '0');
		int carry = 0, t;
		for (int i = 0; i != max; ++ i) {
			t = 0;
			if (m > i && a[m-i-1] == '1') {
				++ t;
			}
			if (n > i && b[n-i-1] == '1') {
				++ t;
			}
			t += carry;
			carry = t / 2;
			t %= 2;
			if (t) {
				s[max-1-i] = '1';
			}
		}
		if (carry) {
			return "1" + s;
		} else {
			return s;
		}
	}
};

int main() {
	Solution sol = Solution();
	string a, b;
	cin >> a >> b;
	cout << sol.addBinary(a, b) << endl;
	return 0;
}
