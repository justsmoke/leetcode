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
		stack<pair<int, int> > seq;
		int last = 0, max = 0, i;
		for (auto it = s.begin(); it != s.end(); ++ it) {
			i = (*it == '(' ? 1 : -1);
			if (last == 0) {
				last = i;
			} else if (last * i > 0) {
				last += i;
			} else {
				pair<int, int> p = make_pair(-i, -i * last);
				last = i;
				int k = handle(seq, p);
				if (k > max) {
					max = k;
				}
			}
		}
		pair<int, int> p = make_pair(i, i * last);
		int k = handle(seq, p);
		return max > k ? max : k;
	}
	int handle(stack<pair<int, int> > &seq, pair<int, int> p) {
		if (!seq.size() && p.first == -1) {
			return 0;
		}
		if (p.first == 1) {
			seq.push(p);
			return 0;
		}
		int c = 0;
		while (seq.size()) {
			pair<int, int> q = seq.top();
			if (q.first == 0) {
				seq.pop();
				c += q.second;
			} else if (q.first == -1) {
				if (c > 0) {
					seq.push(make_pair(0, c));
					seq.push(p);
				} else {
					seq.pop();
					seq.push(make_pair(-1, q.second + p.second));
				}
				return c;
			} else {
				seq.pop();
				if (q.second < p.second) {
					c += 2 * q.second;
					p.second -= q.second;
				} else if (q.second > p.second) {
					c += 2 * p.second;
					seq.push(make_pair(1, q.second - p.second));
					seq.push(make_pair(0, c));
					return c;
				} else {
					c += 2 * p.second;
					if (seq.size() == 0) {
						seq.push(make_pair(0, c));
						return c;
					} else {
						pair<int, int> r = seq.top();
						if (r.first == 0) {
							seq.pop();
							c += r.second;
							seq.push(make_pair(0, c));
						} else {
							seq.push(make_pair(0, c));
						}
						return c;
					}
				}
			}
		}
		seq.push(make_pair(0, c));
		seq.push(p);
		return c;
	}
};

int main() {
	Solution sol = Solution();
	string s;
	while (cin >> s) {
		cout << sol.longestValidParentheses(s) << "#" << s.length() << endl;
	}
	return 0;
}
