//author: zhangyf
//Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
//Return all such possible sentences.
//For example, given
//s = "catsanddog",
//dict = ["cat", "cats", "and", "sand", "dog"].
//A solution is ["cats and dog", "cat sand dog"].

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		if (s == "") {
			return vector<string>();
		}
		vector<vector<int> > step(s.length(), vector<int>());
		for (int i = 0; i != s.length(); ++ i) {
			for (int j = i; j != s.length(); ++ j) {
				if (dict.count(s.substr(i, j - i + 1))) {
					step[j].push_back(i - 1);
				}
			}
		}
		vector<string> ret;
		dfs(ret, s, step, s.length() - 1, "");
		return ret;
	}

	void dfs(vector<string> &ret, string s, vector<vector<int> > step, int pos, string trace) {
		if (pos == -1) {
			ret.push_back(trace);
		} else {
			for (vector<int>::iterator it = step[pos].begin(); it != step[pos].end(); ++ it) {
				string addition(trace == "" ? "" : " " + trace);
				dfs(ret, s, step, *it, s.substr(*it + 1, pos - *it) + addition);
			}
		}
	}
};

int main() {
	Solution sol = Solution();
	string s("aaaa");
	unordered_set<string> dict;
	dict.insert("a");
	dict.insert("aa");
	dict.insert("aaa");
	dict.insert("aaaa");
	vector<string> ans = sol.wordBreak(s, dict);
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); ++ it) {
		cout << *it << "$" << endl;
	}
	return 0;
}
