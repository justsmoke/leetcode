//Given a binary tree, find the maximum path sum.
//The path may start and end at any node in the tree.

#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int max = INT_MIN;

	int maxSinglePathSum(TreeNode *n) {
		if (!n) {
			return 0;
		}
		int ret = n->val;
		int i = maxSinglePathSum(n->left);
		int j = maxSinglePathSum(n->right);
		int k = i > j ? i : j;
		ret += k > 0 ? k : 0;
		int m = n->val;
		m += i > 0 ? i : 0;
		m += j > 0 ? j : 0;
		max = m > max ? m : max;
		return ret;
	}

	int maxPathSum(TreeNode *root) {
		if (!root) {
			return 0;
		}
		maxSinglePathSum(root);
		return max;
	}
};

int main() {
	Solution sol = Solution();
	TreeNode *root = new TreeNode(1);
	TreeNode *left = new TreeNode(-2);
	TreeNode *right = new TreeNode(3);
	root->left = left;
	root->right = right;
	cout << sol.maxPathSum(root) << endl;
	return 0;
}
