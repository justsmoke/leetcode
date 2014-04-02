//Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int l = s.length();
		if (l == 0) {
			return "";
		}
		string ret = s.substr(0, 1);
		int maxLen = 1;
		vector<int> v(1, 0);
		for (int i = 1; i != l; ++ i) {
			int size = v.size();
			for (int j = 0; j != size; ++ j) {
				if (v[j] && s[v[j]-1] == s[i]) {
					v.push_back(v[j]-1);
					if (i-v[j]+2 > maxLen) {
						maxLen = i-v[j]+2;
						ret = s.substr(v[j]-1, maxLen);
					}
				}
			}
			if (s[i-1] == s[i]) {
				v.push_back(i-1);
				if (2 > maxLen) {
					maxLen = 2;
					ret = s.substr(i-1, 2);
				}
			}
			v.push_back(i);
			v.erase(v.begin(), v.begin()+size);
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	string s;
	cin >> s;
	cout << sol.longestPalindrome(s) << endl;
	return 0;
}
