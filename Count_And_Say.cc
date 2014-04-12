//The count-and-say sequence is the sequence of integers beginning as follows:
//1, 11, 21, 1211, 111221, ...
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth sequence.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if (n == 0) {
			return "";
		}
		string s("1");
		char prev;
		int c;
		while (-- n) {
			string t("");
			prev = s[0];
			c = 1;
			for (int i = 1; i < s.length(); ++ i) {
				if (s[i] == prev) {
					c += 1;
				} else {
					t.append(1, c + '0');
					t.append(1, prev);
					prev = s[i];
					c = 1;
				}
			}
			t.append(1, c + '0');
			t.append(1, prev);
			s = t;
		}
		return s;
	}
};

int main() {
	Solution sol = Solution();
	cout << sol.countAndSay(10) << endl;
	return 0;
}
