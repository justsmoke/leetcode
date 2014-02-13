//Say you have an array for which the ith element is the price of a given stock on day i.
//If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() < 2) {
			return 0;
		}
		int min = prices[0], max = min, diff = 0;
		for (vector<int>::iterator it = prices.begin() + 1; it != prices.end(); ++ it) {
			if (*it > max) {
				max = *it;
			} else if (*it < min) {
				diff = (max - min > diff ? max - min : diff);
				min = *it;
				max = *it;
			}
		}
		return max - min > diff ? max - min : diff;
	}
};

int main() {
	Solution sol = Solution();
	vector<int> p;
	p.push_back(2);
	p.push_back(0);
	p.push_back(4);
	cout << sol.maxProfit(p) << endl;
	return 0;
}
