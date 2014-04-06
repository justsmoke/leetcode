//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
	string minWindow(string S, string T) {
		int sLen = S.length(), tLen = T.length();
		if (sLen < tLen || tLen == 0) {
			return "";
		}
		unordered_map<char, int> countMap;
		for (int i = 0; i != tLen; ++ i) {
			countMap[T[i]] += 1;
		}
		int plusPtr = 0, minusPtr = 0, minLen = sLen + 1, start = -1, len;
		char c;
		while (plusPtr < sLen) {
			auto it = countMap.begin();
			while (it != countMap.end()) {
				while (plusPtr < sLen && it->second > 0) {
					c = S[plusPtr ++];
					if (countMap.count(c)) {
						-- countMap[c];
					}
				}
				if (it->second > 0) {
					break;
				} else {
					++ it;
				}
			}
			if (it != countMap.end() && it->second > 0) {
				break;
			}
			while (1) {
				c = S[minusPtr];
				if (countMap.count(c)) {
					if (countMap[c] == 0) {
						break;
					} else if (countMap[c] < 0) {
						++ countMap[c];
					}
				}
				++ minusPtr;
			}
			len = plusPtr - minusPtr;
			if (len < minLen) {
				minLen = len;
				start = minusPtr;
			}
			++ countMap[c];
			++ minusPtr;
		}
		if (minLen == sLen + 1) {
			return "";
		} else {
			return S.substr(start, minLen);
		}
	}
};

int main() {
	Solution sol = Solution();
	string S, T;
	cin >> S >> T;
	cout << sol.minWindow(S, T) << endl;
	return 0;
}
