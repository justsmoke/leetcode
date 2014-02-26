//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

#include <vector>
#include <algorithm>
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
	bool isSymmetric(TreeNode *root) {
		if (!root) {
			return true;
		}
		if (!root->left && !root->right) {
			return true;
		}
		if (!root->left || !root->right) {
			return false;
		}
		vector<TreeNode*> l;
		vector<TreeNode*> r;
		l.push_back(root->left);
		r.push_back(root->right);
		int size = 1;
		while (size) {
			for (int i = 0; i != size; ++ i) {
				TreeNode* s = l[i];
				TreeNode* t = r[i];
				if (!s && !t) {
					continue;
				} else if (!s || !t || s->val != t->val) {
					return false;
				} else {
					l.push_back(s->left);
					l.push_back(s->right);
					r.push_back(t->right);
					r.push_back(t->left);
				}
			}
			l.erase(l.begin(), l.begin() + size);
			r.erase(r.begin(), r.begin() + size);
			size = l.size();
			reverse(r.begin(), r.end());
		}
		return true;
	}
};

int main() {
	Solution sol = Solution();
	return 0;
}
