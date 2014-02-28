//Given a collection of numbers that might contain duplicates, return all possible unique permutations.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int> > permuteUnique(vector<int> &num) {
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
				auto it = ans.rbegin();
				while (it != ans.rend() && *it != n) {
					++ it;
				}
				int l = ans.rend() - it;
				for (int k = i - 1; k >= l; -- k) {
					v.assign(ans.begin(), ans.end());
					v.insert(v.begin() + k, n);
					ret.push_back(v);
				}
			}
			ret.erase(ret.begin(), ret.begin() + c);
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	vector<int> num(2, 3);
	num.push_back(0);
	num.push_back(3);
	num.push_back(1);
	num.push_back(1);
	vector<vector<int> > ret = sol.permuteUnique(num);
	for (auto i = ret.begin(); i != ret.end(); ++ i) {
		for (auto j = (*i).begin(); j != (*i).end(); ++ j) {
			cout << *j << "#";
		}
		cout << endl;
	}
	return 0;
}
