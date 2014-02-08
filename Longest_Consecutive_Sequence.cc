//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		if (!num.size()) {
			return 0;
		}
		unordered_map<int, int> hash;
		unordered_map<int, int> count;
		for (vector<int>::iterator it = num.begin(); it != num.end(); ++ it) {
			int n = *it;
			if (hash.find(n) != hash.end()) {
				continue;
			}
			unordered_map<int, int>::iterator prev = hash.find(n-1);
			unordered_map<int, int>::iterator next = hash.find(n+1);
			if (prev != hash.end() && next == hash.end()) {
				hash[n] = hash[n-1];
				count[hash[n-1]] += 1;
				count[n] = count[hash[n-1]];
			}
			if (prev == hash.end() && next != hash.end()) {
				hash[n] = n;
				hash[n + count[n+1]] = n;
				count[n] = count[n+1] + 1;
				count[n + count[n+1]] += 1;
			}
			if (prev == hash.end() && next == hash.end()) {
				hash[n] = n;
				count[n] = 1;
			}
			if (prev != hash.end() && next != hash.end()) {
				hash[n] = hash[n-1];
				hash[n + count[n+1]] = hash[n-1];
				count[hash[n-1]] += 1 + count[n+1];
				count[n + count[n+1]] = count[hash[n-1]];
			}
		}
		int max = 1;
		for (unordered_map<int, int>::iterator it = count.begin(); it != count.end(); ++ it) {
			if (it->second > max) {
				max = it->second;
			}
		}
		return max;
	}
};

int main() {
	Solution sol = Solution();
	vector<int> v;
	v.push_back(100);
	v.push_back(4);
	v.push_back(6);
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	cout << sol.longestConsecutive(v) << endl;
	return 0;
}
