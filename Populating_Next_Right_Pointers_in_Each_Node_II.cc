//Follow up for problem "Populating Next Right Pointers in Each Node".
//What if the given tree could be any binary tree? Would your previous solution still work?

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
		TreeLinkNode *head = root, *tail = root, *cur, *tmp;
		while (true) {
			bool first = true;
			do {
				while (head && !head->left && !head->right) {
					head = head->next;
				}
				if (!head) {
					if (first) {
						return;
					} else {
						break;
					}
				}
				if (head->left) {
					if (first) {
						cur = head->left;
						tmp = cur;
						first = false;
					} else {
						cur->next = head->left;
						cur = cur->next;
					}
				}
				if (head->right) {
					if (first) {
						cur = head->right;
						tmp = cur;
						first = false;
					} else {
						cur->next = head->right;
						cur = cur->next;
					}
				}
				head = head->next;
			} while (head);
			cur->next = NULL;
			head = tmp;
			tail = cur;
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
	c->left = e;
	c->right = f;
	sol.connect(root);
	cout << e->next->val << endl;
	return 0;
}
