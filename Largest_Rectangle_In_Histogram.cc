//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		if (!height.size()) {
			return 0;
		}
		int max = 0, t;
		vector<int> h(height);
		stack<int> s;
		for (int i = 0; i != h.size(); ++ i) {
			if (s.empty() || h[s.top()] <= h[i]) {
				s.push(i);
			} else {
				int first;
				while (!s.empty() && h[s.top()] > h[i]) {
					t = h[s.top()] * (i - s.top());
					max = t > max ? t : max;
					first = s.top();
					s.pop();
				}
				if (s.empty()) {
					first = 0;
				}
				h[first] = h[i];
				s.push(first);
				s.push(i);
			}
		}
		int last = s.top();
		while (!s.empty()) {
			t = h[s.top()] * (last - s.top() + 1);
			max = t > max ? t : max;
			s.pop();
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
