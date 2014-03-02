//You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> ret;
		int s = S.length(), l = L.size();
		if (s == 0 || l == 0) {
			return ret;
		}
		int n = L[0].length();
		if (s < n * l) {
			return ret;
		}
		unordered_map<string, int> K;
		unordered_set<string> T;
		for (auto it = L.begin(); it != L.end(); ++ it) {
			K[*it] = K[*it] + 1;
			T.insert(*it);
		}
		vector<vector<int> > occur(n);
		for (int i = 0; i != s - n + 1; ++ i) {
			if (T.count(S.substr(i, n))) {
				occur[i % n].push_back(i);
			}
		}
		for (auto it = occur.begin(); it != occur.end(); ++ it) {
			vector<int> v = *it;
			if (v.size() >= l) {
				int start = 0, last = 0;
				while (last < v.size()) {
					last = start;
					while (last < v.size() && v[last + 1] - v[last] == n) {
						++ last;
					}
					cout << l << "#" << start << "-" << last << endl;
					if (last - start >= l) {
						unordered_map<string, int> J(K);
						int p = start;
						while (p < last) {
							string x = S.substr(v[p], n);
							if (J[x] > 0) {
								-- J[x];
								++ p;
							} else {
								while (last - p >= l) {
									++ start;
									string y = S.substr(v[p], n);
									if (y == x) {
										++ p;
										break;
									} else {
										++ J[y];
									}
								}
							}
							if (p - start + 1 == l) {
								ret.push_back(v[start]);
								++ J[S.substr(v[start], n)];
								++ start;
							}
						}
					}
					start = last;
				}
			}
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	vector<string> L;
	L.push_back("a");
	L.push_back("b");
	L.push_back("c");
	vector<int> ret = sol.findSubstring("abcdabcabcd", L);
	for (auto it = ret.begin(); it != ret.end(); ++ it) {
		cout << *it << "#";
	}
	cout << endl;
	return 0;
}
