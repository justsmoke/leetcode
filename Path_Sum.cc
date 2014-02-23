//Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

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
	bool hasPathSum(TreeNode *root, int sum) {
		if (!root) {
			return false;
		}
		sum -= root->val;
		if (sum == 0 && !root->left && !root->right) {
			return true;
		}
		return (root->left && hasPathSum(root->left, sum)) || (root->right && hasPathSum(root->right, sum));
	}
};

int main() {
	Solution sol = Solution();
	TreeNode *a = new TreeNode(5);
	TreeNode *b = new TreeNode(4);
	TreeNode *c = new TreeNode(8);
	TreeNode *d = new TreeNode(11);
	TreeNode *e = new TreeNode(13);
	TreeNode *f = new TreeNode(4);
	TreeNode *g = new TreeNode(7);
	TreeNode *h = new TreeNode(2);
	TreeNode *i = new TreeNode(1);
	a->left = b;
	a->right = c;
	b->left = d;
	c->left = e;
	c->right = f;
	d->left = g;
	d->right = h;
	f->right = i;
	for (int i = 1; i != 30; ++ i) {
		if (sol.hasPathSum(a, i)) {
			cout << i << endl;
		}
	}
	return 0;
}
