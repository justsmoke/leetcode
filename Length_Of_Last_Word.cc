//Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		if (!s) {
			return 0;
		}
		int ret = 0;
		int i = 0, j = 0;
		while (1) {
			while (s[i] == ' ') {
				++ i;
			}
			if (s[i] == '\0') {
				break;
			}
			j = i;
			while (s[j] != '\0' && s[j] != ' ') {
				++ j;
			}
			ret = j - i;
			i = j;
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	cout << sol.lengthOfLastWord("    day") << endl;
	cout << sol.lengthOfLastWord(" asd ") << endl;
	cout << sol.lengthOfLastWord("      asd") << endl;
	cout << sol.lengthOfLastWord("asd  ") << endl;
	cout << sol.lengthOfLastWord(" as asd ") << endl;
	return 0;
}
