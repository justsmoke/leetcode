//Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
//You have the following 3 operations permitted on a word:
//a) Insert a character
//b) Delete a character
//c) Replace a character

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.length(), m = word2.length();
		vector<int> v;
		for (int i = 0; i <= n; ++ i) {
			v.push_back(i);
		}
		for (int i = 1; i <= m; ++ i) {
			vector<int> u(1, i);
			char c = word2[i-1];
			for (int j = 1; j <= n; ++ j) {
				int min = u.back() < v[j] ? u.back() + 1 : v[j] + 1;
				int t = v[j-1] + (c == word1[j-1] ? 0 : 1);
				min = t < min ? t : min;
				u.push_back(min);
			}
			v.assign(u.begin(), u.end());
		}
		return v.back();
	}
};

int main() {
	Solution sol = Solution();
	string s, t;
	cin >> s >> t;
	cout << sol.minDistance(s, t) << endl;
	return 0;
}
