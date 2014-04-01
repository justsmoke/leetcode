//Given a sorted linked list, delete all duplicates such that each element appear only once.

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (!head) {
			return NULL;
		}
		ListNode *ret = head;
		while (head->next) {
			if (head->val == head->next->val) {
				head->next = head->next->next;
			} else {
				head = head->next;
			}
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(1);
	ListNode *c = new ListNode(2);
	ListNode *d = new ListNode(2);
	ListNode *e = new ListNode(2);
	ListNode *f = new ListNode(3);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	auto ret = sol.deleteDuplicates(a);
	while (ret) {
		cout << ret->val << "#";
		ret = ret->next;
	}
	cout << endl;
	return 0;
}
