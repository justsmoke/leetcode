//Given numRows, generate the first numRows of Pascal's triangle.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > ret;
		if (!numRows) {
			return ret;
		}
		vector<int> v(1, 1);
		ret.push_back(v);
		for (int i = 1; i != numRows; ++ i) {
			for (int j = 0; j != i-1; ++ j) {
				v[j] = v[j] + v[j+1];
			}
			v.insert(v.begin(), 1);
			v[i] = 1;
			ret.push_back(v);
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	vector<vector<int> > ret = sol.generate(2);
	for (vector<vector<int> >::iterator i = ret.begin(); i != ret.end(); ++ i) {
		for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); ++ j) {
			cout << *j << '#';
		}
		cout << endl;
	}
	return 0;
}
