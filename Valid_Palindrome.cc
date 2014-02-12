//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isAlphaNumeric(char &c) {
		if (c >= 'A' && c <= 'Z') {
			c -= 'A' - 'a';
		}
		return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'));
	}

	bool isPalindrome(string s) {
		if (s == "") {
			return true;
		}
		int i = 0, j = s.length() - 1;
		while (i < j) {
			while (!isAlphaNumeric(s[i]) && i < j) {
				++ i;
			}
			while (!isAlphaNumeric(s[j]) && i < j) {
				-- j;
			}
			if (i < j && s[i] != s[j]) {
				return false;
			}
			++ i;
			-- j;
		}
		return true;
	}
};

int main() {
	Solution sol = Solution();
	if (sol.isPalindrome("race a car")) {
		cout << "YES" << endl;
	}
	return 0;
}
