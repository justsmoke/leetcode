//Given a singly linked list L: L0→L1→…→Ln-1→Ln,
//reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//You must do this in-place without altering the nodes' values.

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode *head) {
		if (!head) {
			return;
		}
		ListNode *middle = head, *tmp = head;
		while (tmp) {
			middle = middle->next;
			tmp = tmp->next;
			if (tmp) {
				tmp = tmp->next;
			}
		}
		stack<ListNode*> lnStack;
		int size = 0;
		tmp = middle;
		while (tmp) {
			lnStack.push(tmp);
			tmp = tmp->next;
			++ size;
		}
		ListNode *n;
		tmp = head;
		while (size --) {
			n = tmp->next;
			tmp->next = lnStack.top();
			lnStack.pop();
			tmp = tmp->next;
			if (n == middle) {
				break;
			}
			tmp->next = n;
			tmp = n;
		}
		tmp->next = NULL;
	}
};

int main() {
	Solution sol = Solution();
	int n = 11;
	vector<ListNode*> vecListNode;
	for (int i = 0; i != n; ++ i) {
		vecListNode.push_back(new ListNode(i));
		if (i) {
			vecListNode[i-1]->next = vecListNode[i];
		}
	}
	sol.reorderList(vecListNode[0]);
	ListNode *root = vecListNode[0];
	while (root) {
		cout << root->val << "#";
		root = root->next;
	}
	cout << endl;
	return 0;
}
