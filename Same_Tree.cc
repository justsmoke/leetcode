//Given two binary trees, write a function to check if they are equal or not.
//Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

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
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if (!p && !q) {
			return true;
		}
		if (!p || !q) {
			return false;
		}
		vector<TreeNode*> vp;
		vector<TreeNode*> vq;
		vp.push_back(p);
		vq.push_back(q);
		while (vp.size() && vp.size()) {
			int size = vp.size();
			for (int i = 0; i != size; ++ i) {
				TreeNode* x = vp[i];
				TreeNode* y = vq[i];
				if (x->val != y->val) {
					return false;
				}
				if ((x->left && !y->left) || (x->right && !y->right)
						|| (!x->left && y->left) || (!x->right && y->right)) {
					return false;
				}
				if (x->left && y->left) {
					vp.push_back(x->left);
					vq.push_back(y->left);
				}
				if (x->right && y->right) {
					vp.push_back(x->right);
					vq.push_back(y->right);
				}
			}
			vp.erase(vp.begin(), vp.begin() + size);
			vq.erase(vq.begin(), vq.begin() + size);
		}
		return true;
	}
};

int main() {
	Solution sol = Solution();
	return 0;
}
