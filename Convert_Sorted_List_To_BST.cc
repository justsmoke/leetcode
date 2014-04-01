//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		if (!head) {
			return NULL;
		}
		ListNode *n = head;
		int length = 1;
		while (n->next) {
			++ length;
			n = n->next;
		}
		unordered_map<int, TreeNode*> treeMap;
		TreeNode *ret = position(0, length-1, treeMap);
		n = head;
		for (int i = 0; i != length; ++ i) {
			treeMap[i]->val = n->val;
			n = n->next;
		}
		return ret;
	}
	TreeNode *position(int left, int right, unordered_map<int, TreeNode*> &treeMap) {
		if (left > right) {
			return NULL;
		}
		int mid = (left+right)/2;
		TreeNode *root = new TreeNode(mid);
		treeMap[mid] = root;
		root->left = position(left, mid-1, treeMap);
		root->right = position(mid+1, right, treeMap);
		return root;
	}
};

int main() {
	Solution sol = Solution();
	return 0;
}
