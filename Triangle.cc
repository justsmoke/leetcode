//Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int len = triangle.size();
		if (!len) {
			return 0;
		}
		vector<int> minPathSum;
		int i = len;
		for (vector<vector<int> >::reverse_iterator rit = triangle.rbegin(); rit != triangle.rend(); ++ rit) {
			if (i == len) {
				minPathSum = *rit;
			} else {
				for (int j = 0; j != i; ++ j) {
					minPathSum[j] = (*rit)[j] + min(minPathSum[j], minPathSum[j+1]);
				}
			}
			-- i;
		}
		return minPathSum[0];
	}
	int min(int x, int y) {
		return x < y ? x : y;
	}
};

int main() {
	Solution sol = Solution();
	vector<vector<int> > triangle;
	triangle.push_back(vector<int>({2}));
	triangle.push_back(vector<int>({3,4}));
	triangle.push_back(vector<int>({6,5,7}));
	triangle.push_back(vector<int>({4,1,8,3}));
	cout << sol.minimumTotal(triangle) << endl;
	return 0;
}
