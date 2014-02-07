//author: zhangyf
//Sort a linked list using insertion sort.
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if (!head || !head->next) {
			return head;
		}
		ListNode *i = head, *j, *k;
		while (i->next) {
			if (i->next->val >= i->val) {
				i = i->next;
			} else if (i->next->val < head->val) {
				j = i->next->next;
				i->next->next = head;
				head = i->next;
				i->next = j;
			} else {
				j = head;
				while (i->next->val > j->next->val) {
					j = j->next;
				}
				k = i->next->next;
				i->next->next = j->next;
				j->next = i->next;
				i->next = k;
			}
		}
		return head;
	}
};

int main() {
	Solution sol = Solution();
	int n = 11;
	vector<ListNode*> vecListNode;
	srand(time(0));
	for (int i = 0; i != n; ++ i) {
		vecListNode.push_back(new ListNode(rand() % 100));
		if (i) {
			vecListNode[i-1]->next = vecListNode[i];
		}
	}
	ListNode *head = sol.insertionSortList(vecListNode[0]);
	while (head) {
		cout << head->val << "#";
		head = head->next;
	}
	cout << endl;
	return 0;
}
