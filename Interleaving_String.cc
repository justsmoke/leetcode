//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
		if (l1 + l2 != l3) {
			return false;
		}
		bool ans[l1+1][l2+1];
		ans[0][0] = true;
		for (int i = 1; i <= l2; ++ i) {
			ans[0][i] = (s2.substr(0, i) == s3.substr(0, i));
		}
		for (int i = 1; i <= l1; ++ i) {
			ans[i][0] = (s1.substr(0, i) == s3.substr(0, i));
		}
		for (int i = 1; i <= l1; ++ i) {
			for (int j = 1; j <= l2; ++ j) {
				ans[i][j] = ((ans[i-1][j] && (s1[i-1] == s3[i+j-1])) 
						|| (ans[i][j-1] && (s2[j-1] == s3[i+j-1])));
			}
		}
		return ans[l1][l2];
	}
};

int main() {
	Solution sol = Solution();
	string s1, s2, s3;
	cin >> s1;
	cin >> s2;
	cin >> s3;
	if (sol.isInterleave(s1, s2, s3)) {
		cout << "YES" << endl;
	}
	return 0;
}
