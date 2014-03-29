//Given a string s, partition s such that every substring of the partition is a palindrome.
//Return all possible palindrome partitioning of s.

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> ret;
		if (s.length() < 2) {
			ret.push_back(vector<string>(1, s));
			return ret;
		}
		vector<vector<int>> path(s.length());
		for (int i = 1; i <= s.length(); ++ i) {
			for (int j = 0; j <= s.length() - i; ++ j) {
				if (i == 1 || (i == 2 && s[j] == s[j+1])) {
					path[j].push_back(j+i-1);
				} else if (i > 2) {
					auto k = path[j+1].rbegin();
					if ((*k == j+i-2 || (k+1 != path[j+1].rend() && *(k+1) == j+i-2))
						   	&& (s[j] == s[j+i-1])) {
						path[j].push_back(j+i-1);
					}
				}
			}
		}
		vector<int> v;
		vector<vector<int>> mark;
		dfs(mark, path, 0, s.length(), v);

		for (auto i = mark.begin(); i != mark.end(); ++ i) {
			vector<string> t;
			int start = 0;
			for (auto j = (*i).begin(); j != (*i).end(); ++ j) {
				t.push_back(s.substr(start, *j - start));
				start = *j;
			}
			ret.push_back(t);
		}
		return ret;
	}
	void dfs(vector<vector<int>> &ret, vector<vector<int>> path, int start, int end, vector<int> v) {
		if (start == end) {
			ret.push_back(v);
		} else {
			for (auto i = path[start].begin(); i != path[start].end(); ++ i) {
				vector<int> u(v);
				u.push_back(*i + 1);
				dfs(ret, path, *i + 1, end, u);
			}
		}
	}
};

int main() {
	Solution sol = Solution();
	string s;
	cin >> s;
	auto ret = sol.partition(s);
	for (auto i = ret.begin(); i != ret.end(); ++ i) {
		vector<string> ans = *i;
		for (auto j = ans.begin(); j != ans.end(); ++ j) {
			cout << *j << "#";
		}
		cout << endl;
	}
	return 0;
}
