//Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:
//Only one letter can be changed at a time
//Each intermediate word must exist in the dictionary

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		int len = start.length();
		if (!len || !end.length() || len != end.length()) {
			return 0;
		}
		if (start == end) {
			return 1;
		}
		if (!dict.size()) {
			return 0;
		}
		unordered_set<string> remaining(dict);
		remaining.insert(end);
		queue<string> bfs;
		bfs.push(start);
		int distance = 1;
		while (1) {
			++ distance;
			int size = bfs.size();
			if (!size) {
				break;
			}
			while (size --) {
				string s = bfs.front();
				bfs.pop();
				for (int i = 0; i != len; ++ i) {
					for (int j = 0; j != 26; ++ j) {
						char c = (char)('a' + j);
						if (c != s[i]) {
							string t(s);
							t[i] = c;
							if (remaining.count(t)) {
								remaining.erase(t);
								if (t == end) {
									return distance;
								}
								bfs.push(t);
							}
						}
					}
				}
			}
		}
		return 0;
	}
};

int main() {
	Solution sol = Solution();
	string start("hit");
	string end("cog");
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	cout << sol.ladderLength(start, end, dict) << endl;
	return 0;
}
