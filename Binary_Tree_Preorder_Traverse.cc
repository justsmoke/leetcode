//author: zhangyf
//Given a binary tree, return the postorder traversal of its nodes' values.

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> ret;
		if (!root) {
			return ret;
		}
		stack<TreeNode*> tnStack;
		tnStack.push(root);
		while (tnStack.size()) {
			TreeNode *tn = tnStack.top();
			tnStack.pop();
			if (tn->right) {
				tnStack.push(tn->right);
			}
			if (tn->left) {
				tnStack.push(tn->left);
			}
			ret.push_back(tn->val);
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	TreeNode root(1);
	TreeNode i(2);
	TreeNode j(3);
	root.right = &i;
	root.left = &j;
	vector<int> ans = sol.postorderTraversal(&root);
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
		cout << *it << "#";
	}
	cout << endl;
	return 0;
}
