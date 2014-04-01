//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *sortedArrayToBST(vector<int> &num) {
		int size = num.size();
		if (size == 0) {
			return NULL;
		}
		unordered_map<int, TreeNode*> treeMap;
		TreeNode *ret = position(0, size-1, treeMap);
		for (auto i = treeMap.begin(); i != treeMap.end(); ++ i) {
			i->second->val = num[i->first];
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
	vector<int> num;
	for (int i = 0; i != 9; ++ i) {
		num.push_back(2*i+1);
	}
	auto ret = sol.sortedArrayToBST(num);
	cout << ret->val << endl;
	vector<TreeNode*> v(1, ret);
	int size = 1;
	while (size) {
		for (int i = 0; i != size; ++ i) {
			if (v[i]->left) {
				cout << v[i]->left->val << " ";
				v.push_back(v[i]->left);
			} else {
				cout << "# ";
			}
			if (v[i]->right) {
				cout << v[i]->right->val << " ";
				v.push_back(v[i]->right);
			} else {
				cout << "# ";
			}
		}
		cout << endl;
		v.erase(v.begin(), v.begin() + size);
		size = v.size();
	}
	return 0;
}
