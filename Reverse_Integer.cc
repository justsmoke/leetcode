//Reverse digits of an integer.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		if (x == 0) {
			return 0;
		}
		if (x < 0) {
			return -reverse(-x);
		}
		vector<int> s;
		while (x) {
			s.push_back(x % 10);
			x /= 10;
		}
		int ret = 0;
		auto p = s.begin();
		while (*p == 0) {
			++ p;
		}
		while (p != s.end()) {
			ret *= 10;
			ret += *p;
			++ p;
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	int i;
	cin >> i;
	cout << sol.reverse(i) << endl;
	return 0;
}
