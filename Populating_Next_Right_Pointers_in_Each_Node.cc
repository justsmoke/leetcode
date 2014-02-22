//Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

#include <vector>
#include <iostream>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) {
			return;
		}
		root->next = NULL;
		TreeLinkNode *head = root, *tail = root, *tmp;
		while (head->left) {
			tmp = head->left;
			while (head != tail) {
				head->left->next = head->right;
				head->right->next = head->next->left;
				head = head->next;
			}
			tail->left->next = tail->right;
			tail->right->next = NULL;
			head = tmp;
			tail = tail->right;
		}
	}
};

int main() {
	Solution sol = Solution();
	TreeLinkNode *root = new TreeLinkNode(0);
	TreeLinkNode *a = new TreeLinkNode(1);
	TreeLinkNode *b = new TreeLinkNode(2);
	TreeLinkNode *c = new TreeLinkNode(3);
	TreeLinkNode *d = new TreeLinkNode(4);
	TreeLinkNode *e = new TreeLinkNode(5);
	TreeLinkNode *f = new TreeLinkNode(6);
	root->left = a;
	root->right = b;
	a->left = c;
	a->right = d;
	b->left = e;
	b->right = f;
	sol.connect(root);
	return 0;
}
