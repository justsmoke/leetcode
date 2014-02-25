//Given a binary tree, find its maximum depth.

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
	int maxDepth(TreeNode *root) {
		if (!root) {
			return 0;
		}
		vector<TreeNode*> bfs;
		bfs.push_back(root);
		int depth = 0;
		while (bfs.size()) {
			++ depth;
			int size = bfs.size();
			for (int i = 0; i != size; ++ i) {
				TreeNode* node = bfs[i];
				if (node->left) {
					bfs.push_back(node->left);
				}
				if (node->right) {
					bfs.push_back(node->right);
				}
			}
			bfs.erase(bfs.begin(), bfs.begin() + size);
		}
		return depth;
	}
};

int main() {
	Solution sol = Solution();
	TreeNode *r = new TreeNode(1);
	TreeNode *a = new TreeNode(2);
	r->left = a;
	cout << sol.maxDepth(r) << endl;
	return 0;
}
