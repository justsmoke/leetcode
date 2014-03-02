//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<vector<string> > ret(1, vector<string>(1, ""));
		for (int i = 1; i != n + 1; ++ i) {
			vector<string> ans;
			for (int j = 0; j != i; ++ j) {
				for (auto first = ret[j].begin(); first != ret[j].end(); ++ first) {
					for (auto second = ret[i-1-j].begin(); second != ret[i-1-j].end(); ++ second) {
						string s;
						s.append(*first);
						s.append("(");
						s.append(*second);
						s.append(")");
						ans.push_back(s);
					}
				}
			}
			ret.push_back(ans);
		}
		return ret.back();
	}
};

int main() {
	Solution sol = Solution();
	int n;
	cin >> n;
	vector<string> vs = sol.generateParenthesis(n);
	for (auto k = vs.begin(); k != vs.end(); ++ k) {
		cout << *k << endl;
	}
	return 0;
}
