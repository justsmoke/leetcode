//author: zhangyf
//Given a linked list, determine if it has a cycle in it.
//Follow up:
//Can you solve it without using extra space?

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
	ListNode *detectCycle(ListNode *head) {
		if (!head) {
			return NULL;
		}
		ListNode *slow = head, *fast = head;
		while (1) {
			slow = slow->next;
			fast = fast->next;
			if (!fast || !fast->next) {
				return NULL;
			}
			fast = fast->next;
			if (slow == fast) {
				break;
			}
		}
		while (head != slow) {
			head = head->next;
			slow = slow->next;
		}
		return head;
	}
};

int main() {
	Solution sol = Solution();
	ListNode *i = new ListNode(1);
	ListNode *j = new ListNode(2);
	ListNode *k = new ListNode(2);
	i->next = j;
	j->next = k;
	k->next = j;
	ListNode *x = sol.detectCycle(i);
	if (x) {
		cout << x->val << endl;
	}
	return 0;
}
