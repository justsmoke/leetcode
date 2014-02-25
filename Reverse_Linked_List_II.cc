//Reverse a linked list from position m to n. Do it in-place and in one-pass.

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		if (m == n) {
			return head;
		}
		ListNode *p = head;
		int i;
		for (i = 1; i < m - 1; ++ i) {
			p = p->next;
		}
		ListNode *q = p;
		ListNode *s;
		p = p->next;
		for (; i != n - 1; ++ i) {
			s = p->next;
			p->next = s->next;
			s->next = q->next;
			q->next = s;
			ListNode *t = head;
		}
		if (m == 1) {
			s = head->next;
			head->next = p->next;
			p->next = head;
			return s;
		}
		return head;
	}
};

int main() {
	Solution sol = Solution();
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	ListNode *d = new ListNode(4);
	ListNode *e = new ListNode(5);
	ListNode *f = new ListNode(6);
	ListNode *g = new ListNode(7);
	ListNode *h = new ListNode(8);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = g;
	g->next = h;
	int m, n;
	cin >> m >> n;
	ListNode *t = sol.reverseBetween(a, m, n);
	while (t) {
		cout << t->val << "#";
		t = t->next;
	}
	cout << endl;
	return 0;
}
