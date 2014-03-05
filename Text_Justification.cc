//Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
//You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
//Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//For the last line of text, it should be left justified and no extra space is inserted between words.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> ret;
		vector<string> ans;
		int cur = -1;
		for (auto it = words.begin(); it != words.end();) {
			string s(*it);
			if (cur + 1 + s.length() > L) {
				ret.push_back(make_line(ans, cur, L));
				cur = -1;
				ans.clear();
			} else {
				cur += (s.length() + 1);
				ans.push_back(s);
				++ it;
			}
		}
		string t;
		for (auto it = ans.begin(); it != ans.end(); ++ it) {
			if (it > ans.begin()) {
				t.append(" ");
			}
			t.append(*it);
		}
		if (L > cur) {
			t.append(string(L - cur, ' '));
		}
		ret.push_back(t);
		return ret;
	}

	string make_line(vector<string> ans, int cur, int L) {
		auto k = ans.begin();
		string t(*k);
		int count = ans.size() - 1;
		if (count == 0) {
			t.append(string(L - t.length(), ' '));
			return t;
		}
		int space = L - cur;
		int per_space = 1 + space / count;
		int extra_space = space % count;
		for (int i = 0; i != extra_space; ++ i) {
			++ k;
			string sp(per_space + 1, ' ');
			t.append(sp);
			t.append(*k);
		}
		for (int i = 0; i != count - extra_space; ++ i) {
			++ k;
			string sp(per_space, ' ');
			t.append(sp);
			t.append(*k);
		}
		return t;
	}
};

int main() {
	Solution sol = Solution();
	vector<string> words;
	words.push_back("This");
	words.push_back("is");
	words.push_back("an");
	words.push_back("example");
	words.push_back("of");
	words.push_back("text");
	words.push_back("justification.");
	vector<string> v = sol.fullJustify(words, 16);
	cout << v.size() << endl;
	cout << v[0] << endl;
	cout << v[1] << endl;
	cout << v[2] << endl;
	return 0;
}
