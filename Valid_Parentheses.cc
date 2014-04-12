//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#include <vector>
#include <stack>
#include <utility>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s.length() == 0) {
			return true;
		}
		stack<pair<char, int>> stk;
		unordered_map<char, char> match;
		match[')'] = '(';
		match[']'] = '[';
		match['}'] = '{';
		for (int i = 0; i != s.length(); ++ i) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				if (stk.empty() || stk.top().first != s[i]) {
					stk.push(make_pair(s[i], 1));
				} else {
					stk.top().second += 1;
				}
			} else if ((s[i] == ')' || s[i] == ']' || s[i] == '}') && 
					!stk.empty() && match[s[i]] == stk.top().first) {
				if (stk.top().second == 1) {
					stk.pop();
				} else {
					stk.top().second -= 1;
				}
			} else {
				return false;
			}
		}
		return stk.empty();
	}
};

int main() {
	Solution sol = Solution();
	string s;
	cin >> s;
	if (sol.isValid(s)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
