//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		int avg = target / 3;
		auto p = num.begin();
		if (*p >= avg) {
			return num[0] + num[1] + num[2];
		}
		while (p != num.end() && *p < avg) {
			++ p;
		}
		if (p == num.end()) {
			int size = num.size();
			return num[size - 1] + num[size - 2] + num[size - 3];
		}
		int min = num[0] + num[1] + num[2] - target, ret;
		for (auto i = num.begin(); i <= p; ++ i) {
			for (auto j = p; j != num.end(); ++ j) {
				if (j <= i + 1) {
					continue;
				}
				int t = target - *i - *j;
				int diff = closest(i + 1, j - 1, t) - t;
				if (diff == 0) {
					return target;
				}
				if (abs(diff) < abs(min)) {
					min = diff;
				}
			}
		}
		return target + min;
	}
	int closest(vector<int>::iterator b, vector<int>::iterator e, int target) {
		auto p = b;
		if (*p >= target) {
			return *b;
		}
		while (p <= e && *p < target) {
			++ p;
		}
		if (p == e + 1) {
			return *e;
		}
		return abs(*p - target) < abs(*(p - 1) - target) ? *p : *(p - 1);
	}
};

int main() {
	Solution sol = Solution();
	vector<int> num;
	num.push_back(0);
	num.push_back(2);
	num.push_back(1);
	num.push_back(-3);
	int target;
	while (cin >> target) {
		cout << sol.threeSumClosest(num, target) << endl;
	}
	return 0;
}
