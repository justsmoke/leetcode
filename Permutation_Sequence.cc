//Given n and k, return the kth permutation sequence.
//Note: Given n will be between 1 and 9 inclusive.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		string ret;
		vector<int> v;
		int m = 1;
		for (int i = 1; i <= n; ++ i) {
			m *= i;
			v.push_back(i);
		}
		int c = n;
		-- k;
		while (c) {
			m /= c;
			int q = k / m, r = k % m;
			k = r;
			ret += v[q] + '0';
			v.erase(v.begin() + q);
			-- c;
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	int n, k;
	cin >> n >> k;
	cout << sol.getPermutation(n, k) << endl;
	return 0;
}
