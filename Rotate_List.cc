//Given a list, rotate the list to the right by k places, where k is non-negative.

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
	ListNode *rotateRight(ListNode *head, int k) {
		if (!head) {
			return NULL;
		}
		ListNode *n = head;
		int length = 1;
		while (n->next) {
			++ length;
			n = n->next;
		}
		k %= length;
		if (k) {
			ListNode *tail = n;
			tail->next = head;
			ListNode *ret;
			k = length - 1 - k;
			n = head;
			while (k--) {
				n = n->next;
			}
			ret = n->next;
			n->next = NULL;
			return ret;
		} else {
			return head;
		}
	}
};

int main() {
	Solution sol = Solution();
	return 0;
}
