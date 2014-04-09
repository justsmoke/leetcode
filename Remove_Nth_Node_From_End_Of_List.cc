//Given a linked list, remove the nth node from the end of list and return its head.

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
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (!head) {
			return NULL;
		}
		ListNode *ret = head, *i = head, *j = head;
		while (n--) {
			j = j->next;
		}
		if (!j) {
			return head->next;
		}
		while (j->next) {
			i = i->next;
			j = j->next;
		}
		i->next = i->next->next;
		return head;
	}
};

int main() {
	Solution sol = Solution();
	return 0;
}
