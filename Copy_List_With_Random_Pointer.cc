//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//Return a deep copy of the list.

#include <vector>
#include <iostream>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) {
			return NULL;
		}
		RandomListNode *n = head;
		while (n) {
			RandomListNode *t = new RandomListNode(n->label);
			t->next = n->next;
			n->next = t;
			n = t->next;
		}
		n = head;
		while (n) {
			n->next->random = (n->random == NULL ? NULL : n->random->next);
			n = n->next->next;
		}
		n = head;
		RandomListNode *ret = head->next;
		while (n->next->next) {
			RandomListNode *t = n->next;
			n->next = t->next;
			n = t->next;
			t->next = t->next->next;
		}
		n->next = NULL;
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	RandomListNode *v = new RandomListNode(-1);
	sol.copyRandomList(v);
	return 0;
}
