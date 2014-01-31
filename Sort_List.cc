//Sort a linked list in O(n log n) time using constant space complexity.

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
	ListNode *merge(ListNode *left, ListNode *right) {
		ListNode pre(0), *origin = &pre, *k = &pre;
		while (left && right) {
			if (left->val <= right->val) {
				k->next = left;
				left = left->next;
			} else {
				k->next = right;
				right = right->next;
			}
			k = k->next;
		}
		if (left) {
			k->next = left;
		} else {
			k->next = right;
		}
		return origin->next;
	}

	ListNode *sortList(ListNode *head) {
		if (!head || !head->next) {
			return head;
		}
		ListNode pre(0), *origin = &pre;
		origin->next = head;
		ListNode *tmp = head;
		int len = 0;
		while (tmp) {
			++ len;
			tmp = tmp->next;
		}
		int gap = 1;
		while (gap < len) {
			ListNode *left = origin;
			while (left->next) {
				ListNode *right = left, *stop = left;
				int t = gap;
				while (t--) {
					if (right->next) {
						right = right->next;
					}
					if (stop->next) {
						stop = stop->next;
					}
					if (stop->next) {
						stop = stop->next;
					}
				}
				ListNode *p = right->next;
				right->next = NULL;
				ListNode *q = stop->next;
				stop->next = NULL;
				ListNode *merged = merge(left->next, p);
				left->next = merged;
				while (left->next) {
					left = left->next;
				}
				left->next = q;
			}
			gap <<= 1;
		}
		return origin->next;
	}
};

int main() {
	Solution sol = Solution();
	vector<ListNode> vecListNode;
	for (int i = 10; i != 0; -- i) {
		vecListNode.push_back(ListNode(i));
	}
	for (int i = 11; i != 21; ++ i) {
		vecListNode.push_back(ListNode(i));
	}
	ListNode origin(0), *p = &origin, *q = &origin;
	for (vector<ListNode>::iterator it = vecListNode.begin(); it != vecListNode.end(); ++it) {
		p->next = &(*it);
		p = p->next;
	}
	ListNode *head = sol.sortList(q->next);
	while (head) {
		cout << head->val << "#";
		head = head->next;
	}
	cout << endl;
	return 0;
}
