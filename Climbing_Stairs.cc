//You are climbing a stair case. It takes n steps to reach to the top.
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 0) {
			return 0;
		}
		int a = 1, b = 1, t;
		for (int i = 2; i <= n; ++ i) {
			t = a + b;
			a = b;
			b = t;
		}
		return b;
	}
};

int main() {
	Solution sol = Solution();
	int n;
	cin >> n;
	cout << sol.climbStairs(n) << endl;
	return 0;
}
