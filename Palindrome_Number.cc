//Determine whether an integer is a palindrome. Do this without extra space.

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}
		int digits = 0;
		int t = x;
		int left = 1, right = 10;
		while (t > 0) {
			if (t >= 10) {
				left *= 10;
			}
			t /= 10;
			++ digits;
		}
		for (int i = 0; i != digits / 2; ++ i) {
			if ((x / left) % 10 != (x % right) / (right / 10)) {
				return false;
			}
			left /= 10;
			right *= 10;
		}
		return true;
	}
};

int main() {
	Solution sol = Solution();
	int n;
	while (cin >> n) {
		if (sol.isPalindrome(n)) {
			cout << "YES" << endl;
		} else {
			cout << "FALSE" << endl;
		}
	}
	return 0;
}
