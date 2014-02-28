//Given a collection of numbers, return all possible permutations.

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > ret;
		int size = num.size();
		if (!size) {
			return ret;
		}
		ret.push_back(vector<int>(1, num[0]));
		for (int i = 1; i != size; ++ i) {
			int n = num[i];
			int c = ret.size();
			for (int j = 0; j != c; ++ j) {
				vector<int> ans(ret[j]);
				vector<int> v(ans);
				v.push_back(n);
				ret.push_back(v);
				int l = find(ans.begin(), ans.end(), n) - ans.begin();
				if (l == i) {
					l = 0;
				}
				for (int k = i; k != l; -- k) {
					if (ans[k - 1] != n) {
						v.assign(ans.begin(), ans.end());
						v.insert(v.begin() + k - 1, n);
						ret.push_back(v);
					}
				}
			}
			ret.erase(ret.begin(), ret.begin() + c);
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	vector<int> num(2, 1);
	num.push_back(2);
	num.push_back(2);
	num.push_back(3);
	vector<vector<int> > ret = sol.permute(num);
	for (auto i = ret.begin(); i != ret.end(); ++ i) {
		for (auto j = (*i).begin(); j != (*i).end(); ++ j) {
			cout << *j << "#";
		}
		cout << endl;
	}
	return 0;
}
