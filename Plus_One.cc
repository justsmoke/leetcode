//Given a non-negative number represented as an array of digits, plus one to the number.
//The digits are stored such that the most significant digit is at the head of the list.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		vector<int> ret;
		auto rit = digits.rbegin();
		while (rit != digits.rend() && *rit == 9) {
			++ rit;
		}
		if (rit == digits.rend()) {
			ret.push_back(1);
			ret.insert(ret.end(), digits.size(), 0);
		} else {
			int head = digits.rend() - rit;
			ret.assign(digits.begin(), digits.begin() + head - 1);
			ret.push_back(*rit + 1);
			ret.insert(ret.end(), digits.size() - head, 0);
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	vector<int> v(3, 1);
	auto ret = sol.plusOne(v);
	for (auto i = ret.begin(); i != ret.end(); ++ i) {
		cout << *i;
	}
	cout << endl;
	return 0;
}
