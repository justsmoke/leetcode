//Implement floor(sqrt(int x))

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int sqrt(int x) {
		if (x <= 0) {
			return 0;
		}
		int i = 0, t = x;
		while (t >= 1) {
			t >>= 2;
			++ i;
		}
		i = (1 << i);
		int left = i/2, right = i-1, mid;
		if (x/right >= right) {
			return right;
		}
		while (left < right) {
			mid = (left+right)/2;
			if (x/mid < mid) {
				right = mid - 1;
			} else if (x/(mid+1) >= mid+1) {
				left = mid + 1;
			} else {
				return mid;
			}
		}
		return left;
	}
};

int main() {
	Solution sol = Solution();
	int n = 2147395599;
	int i = sol.sqrt(n);
	cout << i*i << "#" << n << endl;
	return 0;
}
