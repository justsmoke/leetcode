//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//The replacement must be in-place, do not allocate extra memory.
//Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int> &num) {
		auto pos = num.rbegin();
		while ((pos + 1 != num.rend()) && (*pos <= *(pos + 1))) {
			++ pos;
		}
		if (pos + 1 != num.rend()) {
			int n = *(pos + 1);
			auto q = num.rbegin();
			while (*q <= n) {
				++ q;
			}
			*(pos + 1) = *q;
			*q = n;
		}
		reverse(num.rbegin(), pos + 1);
		for (auto i = num.begin(); i != num.end(); ++ i) {
			cout << *i << " ";
		}
		cout << endl;
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
		sol.nextPermutation(v);
	}
	return 0;
}
