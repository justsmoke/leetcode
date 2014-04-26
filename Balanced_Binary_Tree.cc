//Given a binary tree, determine if it is height-balanced.

#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int height(TreeNode *root, bool &balanced) {
		if (!balanced || !root) {
			return 0;
		}
		int l = height(root->left, balanced);
		int r = height(root->right, balanced);
		if (l - r > 1 || r - l > 1) {
			balanced = false;
		}
		return l > r ? l + 1 : r + 1;
	}
	bool isBalanced(TreeNode *root) {
		bool ret = true;
		height(root, ret);
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	return 0;
}
