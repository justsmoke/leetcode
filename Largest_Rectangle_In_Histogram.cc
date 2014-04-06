//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		stack<int> s;
		int max = 0, tmp, i = 0, n = height.size();
		while (i < n) {
			if (s.empty() || height[s.top()] <= height[i]) {
				s.push(i);
				++ i;
			} else {
				tmp = s.top();
				s.pop();
				tmp = height[tmp] * (s.empty() ? i : i - s.top() - 1);
				max = tmp > max ? tmp : max;
			}
		}
		while (!s.empty()) {
			tmp = s.top();
			s.pop();
			tmp = height[tmp] * (s.empty() ? i : i - s.top() - 1);
			max = tmp > max ? tmp : max;
		}
		return max;
	}
};

int main() {
	Solution sol = Solution();
	vector<int> v;
	int i;
	while (1) {
		v.clear();
		cin >> i;
		while (i != -1) {
			v.push_back(i);
			cin >> i;
		}
		cout << sol.largestRectangleArea(v) << endl;
	}
	return 0;
}
