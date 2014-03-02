//Given a collection of integers that might contain duplicates, S, return all possible subsets.
//Note:
//Elements in a subset must be in non-descending order.
//The solution set must not contain duplicate subsets.

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		map<int, int> T;
		for (auto it = S.begin(); it != S.end(); ++ it) {
			T[*it] += 1;
		}
		vector<vector<int> > ret;
		ret.push_back(vector<int>());
		for (auto it = T.begin(); it != T.end(); ++ it) {
			int size = ret.size();
			if (size == 0) {
				for (int i = 1; i <= it->second; ++ i) {
					ret.push_back(vector<int>(i, it->first));
				}
			} else {
				for (int i = 0; i != size; ++ i) {
					vector<int> appendant;
					for (int j = 1; j <= it->second; ++ j) {
						vector<int> ans(ret[i]);
						appendant.push_back(it->first);
						ans.insert(ans.end(), appendant.begin(), appendant.end());
						ret.push_back(ans);
					}
				}
			}
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	vector<int> S(2, 2);
	S.push_back(1);
	S.push_back(1);
	S.push_back(3);
	auto ret = sol.subsetsWithDup(S);
	for (auto it = ret.begin(); it != ret.end(); ++ it) {
		vector<int> v = *it;
		for (auto j = v.begin(); j != v.end(); ++ j) {
			cout << *j << "#";
		}
		cout << endl;
	}
	return 0;
}
