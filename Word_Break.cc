//Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
//For example, given
//s = "leetcode",
//dict = ["leet", "code"].
//Return true because "leetcode" can be segmented as "leet code".

#include <vector>
#include <iostream>
#include <unordered_set>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		string t(s);
		t.erase(remove(t.begin(), t.end(), ' '), t.end());
		size_t goal = t.size();
		if (!goal) {
			return true;
		}
		if (!dict.size()) {
			return false;
		}
		map<int, unordered_set<int> > path;
		for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++ it) {
			string word = *it;
			size_t pos = t.find(word);
			size_t len = word.size();
			while (pos != string::npos) {
				path[pos].insert(pos + len);
				pos = t.find(*it, pos + 1);
			}
		}
		vector<int> reachable(goal, 0);
		reachable[0] = 1;
		for (map<int, unordered_set<int> >::iterator it = path.begin(); it != path.end(); ++ it) {
			if (reachable[it->first]) {
				unordered_set<int> next = it->second;
				for (unordered_set<int>::iterator i = next.begin(); i != next.end(); ++ i) {
					if (*i == goal) {
						return true;
					}
					reachable[*i] = 1;
				}
			}
		}
		return false;
	}
};

int main() {
	Solution sol = Solution();
	string s("leetcode");
	unordered_set<string> dict;
	dict.insert("leet");
	dict.insert("code");
	if (sol.wordBreak(s, dict)) {
		cout << "YES" << endl;
	}
	return 0;
}
