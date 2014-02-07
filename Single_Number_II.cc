//Given an array of integers, every element appears three times except for one. Find that single one.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int singleNumber(int A[], int n) {
		int ones = 0, twos = 0, xthrees = 0;
		for (int i = 0; i != n; ++ i) {
			int x = A[i];
			int a = (~xthrees & x) | (ones & ~x);
			int b = (ones & x) | (twos & ~x);
			int c = (twos & x) | (~xthrees & ~x);
			ones = a;
			twos = b;
			xthrees = ~c;
		}
		return ones;
	}
};

int main() {
	Solution sol = Solution();
	int A[13] = {1,2,1,2,3,2,1,3,3,0,0,0,100};
	cout << sol.singleNumber(A, 13) << endl;
	return 0;
}
