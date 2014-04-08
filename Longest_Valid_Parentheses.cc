//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

#include <vector>
#include <string>
#include <utility>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> st;
		vector<pair<int, int>> interval;
		int left, right;
		for (int i = 0; i != s.length(); ++ i) {
			if (s[i] == '(') {
				st.push(i);
			} else if (!st.empty()) {
				left = st.top();
				right = i;
				if (interval.empty()) {
					interval.push_back(make_pair(left, right));
				} else {
					if (left == interval.back().first - 1) {
						interval.pop_back();
						if (!interval.empty() && interval.back().second == left - 1) {
							interval.back().second = right;
						} else {
							interval.push_back(make_pair(left, right));
						}
					} else if (left == interval.back().second + 1) {
						interval.back().second += 2;
					} else if (left > interval.back().second + 1) {
						interval.push_back(make_pair(left, right));
					}
				}
				st.pop();
			}
		}
		int max = 0, t;
		for (auto it = interval.begin(); it != interval.end(); ++ it) {
			t = it->second - it->first + 1;
			max = t > max ? t : max;
		}
		return max;
	}
};

int main() {
	Solution sol = Solution();
	string s;
	while (cin >> s) {
		cout << s.length() << "#" << sol.longestValidParentheses(s) << endl;
	}
	return 0;
}
