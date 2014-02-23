//Given a binary tree, flatten it to a linked list in-place

#include <vector>
#include <stack>
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
	void flatten(TreeNode *root) {
		if (!root) {
			return;
		}
		while (root) {
			if (root->left) {
				TreeNode *rightmost = root->left;
				while (rightmost->right) {
					rightmost = rightmost->right;
				}
				rightmost->right = root->right;
				root->right = root->left;
				root->left = NULL;
			}
			root = root->right;
		}
	}
};

int main() {
	Solution sol = Solution();
	return 0;
}
