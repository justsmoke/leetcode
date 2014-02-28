//Say you have an array for which the ith element is the price of a given stock on day i.
//Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int sz = prices.size();
		if (sz < 2) {
			return 0;
		}
		int i = 0, sum = 0;
		int low, high;
		while (i < sz - 1) {
			while (i < sz - 1 && prices[i] >= prices[i+1]) {
				++ i;
			}
			if (i == sz - 1) {
				break;
			}
			low = prices[i++];
			while (i < sz - 1 && prices[i] <= prices[i+1]) {
				++ i;
			}
			high = prices[i++];
			sum += high - low;
		}
		return sum;
	}
};

int main() {
	Solution sol = Solution();
	vector<int> p;
	p.push_back(5);
	p.push_back(3);
	p.push_back(4);
	p.push_back(9);
	p.push_back(1);
	p.push_back(4);
	p.push_back(3);
	p.push_back(2);
	cout << sol.maxProfit(p) << endl;
	return 0;
}
