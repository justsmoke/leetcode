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
	void dfs(TreeNode *root, int sum, vector<vector<int> > &ret, vector<int> path) {
		sum -= root->val;
		path.push_back(root->val);
		if (sum == 0 && !root->left && !root->right) {
			ret.push_back(path);
		}
		if (root->left) {
			dfs(root->left, sum, ret, path);
		}
		if (root->right) {
			dfs(root->right, sum, ret, path);
		}
	}

	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > ret;
		if (root) {
			dfs(root, sum, ret, vector<int>());
		}
		return ret;
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
	TreeNode *j = new TreeNode(5);
	a->left = b;
	a->right = c;
	b->left = d;
	c->left = e;
	c->right = f;
	d->left = g;
	d->right = h;
	f->left = j;
	f->right = i;
	for (int i = 1; i != 30; ++ i) {
		cout << i << ":" << sol.pathSum(a, i).size() << endl;
	}
	return 0;
}
