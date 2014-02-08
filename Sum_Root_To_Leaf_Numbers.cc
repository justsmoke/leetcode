//Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//An example is the root-to-leaf path 1->2->3 which represents the number 123.
//Find the total sum of all root-to-leaf numbers.

#include <queue>
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
	int sumNumbers(TreeNode *root) {
		if (!root) {
			return 0;
		}
		int sum = 0;
		queue<TreeNode*> bfs;
		bfs.push(root);
		while (bfs.size()) {
			TreeNode *tn = bfs.front();
			int v = tn->val;
			bfs.pop();
			if (tn->left) {
				tn->left->val += 10 * v;
				bfs.push(tn->left);
			}
			if (tn->right) {
				tn->right->val += 10 * v;
				bfs.push(tn->right);
			}
			if (!tn->left && !tn->right) {
				sum += v;
			}
		}
		return sum;
	}
};

int main() {
	Solution sol = Solution();
	TreeNode *root = new TreeNode(1);
	TreeNode *l = new TreeNode(0);
	root->left = l;
	cout << sol.sumNumbers(root) << endl;
	return 0;
}
