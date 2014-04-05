//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//You should preserve the original relative order of the nodes in each of the two partitions.

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *partition(ListNode *head, int x) {
		if (!head) {
			return NULL;
		}
		ListNode *small = new ListNode(0);
		ListNode *large = new ListNode(0);
		ListNode *i = small;
		ListNode *j = large;
		ListNode *k = head;
		while (k) {
			if (k->val < x) {
				i->next = k;
				i = i->next;
			} else {
				j->next = k;
				j = j->next;
			}
			k = k->next;
		}
		if (!small->next || !large->next) {
			return head;
		} else {
			i->next = large->next;
			j->next = NULL;
			return small->next;
		}
	}
};

int main() {
	Solution sol = Solution();
	int i;
	ListNode *head = new ListNode(0);
	ListNode *n = head;
	cin >> i;
	while (i != -1) {
		n->next = new ListNode(i);
		n = n->next;
		cin >> i;
	}
	int x;
	cin >> x;
	ListNode *ret = sol.partition(head->next, x);
	while (ret) {
		cout << ret->val << "->";
		ret = ret->next;
	}
	cout << endl;
	return 0;
}
