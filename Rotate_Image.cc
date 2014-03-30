//You are given an n x n 2D matrix representing an image.
//Rotate the image by 90 degrees (clockwise).
//Follow up:
//Could you do this in-place?

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>> &matrix) {
		//i,j->j,n-i-1->n-i-1,n-j-1->n-j-1,i->i,j
		int n = matrix.size();
		int t;
		for (int i = 0; i != n/2; ++ i) {
			for (int j = 0; j != (n+1)/2; ++ j) {
				t = matrix[i][j];
				matrix[i][j] = matrix[n-j-1][i];
				matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
				matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
				matrix[j][n-i-1] = t;
			}
		}
	}
};

int main() {
	Solution sol = Solution();
	return 0;
}
