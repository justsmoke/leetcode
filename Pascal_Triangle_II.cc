//Given an index k, return the kth row of the Pascal's triangle.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> v(1, 1);
		if (!rowIndex) {
			return v;
		}
		int i = 1;
		while (i <= rowIndex/2) {
			v.push_back(v.back()/i*(rowIndex-i+1) + (v.back()%i)*(rowIndex-i+1)/i);
			++ i;
		}
		vector<int> copy(v);
		vector<int>::reverse_iterator rit = copy.rbegin();
		if (rowIndex % 2 == 0) {
			++ rit;
		}
		for (; rit != copy.rend(); ++ rit) {
			v.push_back(*rit);
		}
		return v;
	}
};

int main() {
	Solution sol = Solution();
	vector<int> ret = sol.getRow(5);
	for (vector<int>::iterator i = ret.begin(); i != ret.end(); ++ i) {
		cout << *i << "#";
	}
	cout << endl;
	return 0;
}
