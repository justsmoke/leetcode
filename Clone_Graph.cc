//Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node) {
			return NULL;
		}
		unordered_map<int, UndirectedGraphNode*> match;
		match[node->label] = new UndirectedGraphNode(node->label);
		queue<UndirectedGraphNode*> bfs;
		bfs.push(node);
		while (bfs.size()) {
			UndirectedGraphNode* n = bfs.front();
			bfs.pop();
			for (vector<UndirectedGraphNode*>::iterator it = n->neighbors.begin();
					it != n->neighbors.end(); ++ it) {
				int l = (*it)->label;
				if (match.find(l) == match.end()) {
					bfs.push(*it);
					match[l] = new UndirectedGraphNode(l);
				}
				match[n->label]->neighbors.push_back(match[l]);
			}
		}
		return match[node->label];
	}
};

int main() {
	Solution sol = Solution();
	return 0;
}
