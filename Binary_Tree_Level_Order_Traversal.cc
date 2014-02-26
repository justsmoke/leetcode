//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

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
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > ret;
		if (!root) {
			return ret;
		}
		vector<TreeNode*> nodes(1, root);
		vector<int> level(1, root->val);
		while (level.size()) {
			ret.push_back(level);
			int size = level.size();
			level.clear();
			for (int i = 0; i != size; ++ i) {
				if (nodes[i]->left) {
					nodes.push_back(nodes[i]->left);
					level.push_back(nodes[i]->left->val);
				}
				if (nodes[i]->right) {
					nodes.push_back(nodes[i]->right);
					level.push_back(nodes[i]->right->val);
				}
			}
			nodes.erase(nodes.begin(), nodes.begin() + size);
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	TreeNode *r = new TreeNode(1);
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(1);
	r->left = a;
	a->right = b;
	vector<vector<int> > ret = sol.levelOrder(r);
	cout << ret[0].size() << ret[1].size() << ret[2].size() << endl;
	return 0;
}
