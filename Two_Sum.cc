//Given an array of integers, find two numbers such that they add up to a specific target number.

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> ret;
		unordered_map<int, int> index;
		int i = 0;
		for (auto it = numbers.begin(); it != numbers.end(); ++ it) {
			++ i;
			int x = target - *it;
			auto pos = index.find(x);
			if (pos != index.end()) {
				ret.push_back(pos->second);
				ret.push_back(i);
				break;
			} else {
				index[*it] = i;
			}
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	vector<int> n({1,2,3,7});
	vector<int> ret = sol.twoSum(n, 4);
	cout << ret[0] << "#" << ret[1] << endl;
	return 0;
}
