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
	bool hasCycle(ListNode *head) {
		ListNode *slow = head, *fast = head;
		while (fast) {
			slow = slow->next;
			fast = fast->next;
			if (!fast) {
				break;
			}
			fast = fast->next;
			if (slow == fast) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	Solution sol = Solution();
	ListNode *i = new ListNode(1);
	ListNode *j = new ListNode(2);
	i->next = j;
	j->next = i;
	if (sol.hasCycle(i)) {
		cout << "has cycle" << endl;
	}
	return 0;
}
