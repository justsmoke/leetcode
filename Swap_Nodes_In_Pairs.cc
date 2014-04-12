//Given a linked list, swap every two adjacent nodes and return its head.
//Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

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
	ListNode *swapPairs(ListNode *head) {
		if (!head || !head->next) {
			return head;
		}
		ListNode *ret = head->next;
		head->next = ret->next;
		ret->next = head;
		head = ret->next;
		while (head->next && head->next->next) {
			ListNode *t = head->next;
			head->next = t->next;
			t->next = head->next->next;
			head->next->next = t;
			head = t;
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	return 0;
}
