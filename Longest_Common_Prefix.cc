//Write a function to find the longest common prefix string amongst an array of strings.

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		if (strs.size() == 0) {
			return "";
		}
		int i = 0, min = INT_MAX;
		for (auto it = strs.begin(); it != strs.end(); ++ it) {
			min = it->length() < min ? it->length() : min;
		}
		if (min == 0) {
			return "";
		}
		while (i <= min) {
			char c = strs[0][i];
			for (auto it = strs.begin() + 1; it != strs.end(); ++ it) {
				if ((*it)[i] != c) {
					return (*it).substr(0, i);
				}
			}
			++ i;
		}
		return strs[0].substr(0, min);
	}
};

int main() {
	Solution sol = Solution();
	return 0;
}
