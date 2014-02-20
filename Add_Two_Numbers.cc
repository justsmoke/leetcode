//You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8

#include <vector>
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *ret = new ListNode(0), *cur = ret;
		int carry = 0, s;
		while (l1 && l2) {
			s = l1->val + l2->val + carry;
			carry = s / 10;
			cur->next = new ListNode(s % 10);
			cur = cur->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l2) {
			s = l2->val + carry;
			carry = s / 10;
			cur->next = new ListNode(s % 10);
			cur = cur->next;
			l2 = l2->next;
		}
		while (l1) {
			s = l1->val + carry;
			carry = s / 10;
			cur->next = new ListNode(s % 10);
			cur = cur->next;
			l1 = l1->next;
		}
		if (carry) {
			cur->next = new ListNode(1);
		}
		return ret->next;
	}
};

int main() {
	Solution sol = Solution();
	return 0;
}
