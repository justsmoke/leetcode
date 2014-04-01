//Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	void sortColors(int A[], int n) {
		int i = 0, j = 0, k = 0, t;
		for (int p = 0; p != n; ++ p) {
			t = A[p];
			A[k++] = 2;
			if (t == 1) {
				A[j++] = 1;
			} else if (t == 0) {
				A[j++] = 1;
				A[i++] = 0;
			}
		}
	}
};

int main() {
	Solution sol = Solution();
	int A[] = {1,2,0,2,0,0,0,1,1,2,0,0,2,1};
	for (int i = 0; i != 14; ++ i) {
		cout << A[i] << "#";
	}
	cout << endl;
	sol.sortColors(A, 14);
	for (int i = 0; i != 14; ++ i) {
		cout << A[i] << "#";
	}
	cout << endl;
	return 0;
}
