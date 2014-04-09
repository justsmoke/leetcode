//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int>> ret;
		if (k == 0) {
			return ret;
		}
		if (k == n) {
			vector<int> v;
			for (int i = 1; i <= n; ++ i) {
				v.push_back(i);
			}
			ret.push_back(v);
			return ret;
		}
		bool reverse = false;
		if (k > n / 2) {
			reverse = true;
			k = n - k;
		}
		dfs(n, k, vector<int>(), ret);
		if (reverse) {
			return reverseVector(ret, n);
		} else {
			return ret;
		}
	}
	void dfs(int n, int k, vector<int> current, vector<vector<int>> &ret) {
		int size = current.size();
		if (size == k) {
			ret.push_back(current);
		} else {
			int start = (size == 0 ? 1 : current.back() + 1);
			for (int next = start; next <= n + 1 - k + size; ++ next) {
				vector<int> v(current);
				v.push_back(next);
				dfs(n, k, v, ret);
			}
		}
	}
	vector<vector<int>> reverseVector(vector<vector<int>> v, int n) {
		vector<vector<int>> ret;
		for (auto i = v.begin(); i != v.end(); ++ i) {
			int p = 1;
			vector<int> ans;
			for (auto j = i->begin(); j != i->end(); ++ j) {
				for (int k = p; k != *j; ++ k) {
					ans.push_back(k);
				}
				p = *j + 1;
			}
			for (int k = p; k <= n; ++ k) {
				ans.push_back(k);
			}
			ret.push_back(ans);
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	int n, k;
	cin >> n >> k;
	auto ret = sol.combine(n, k);
	cout << ret.size() << endl;
	return 0;
}
