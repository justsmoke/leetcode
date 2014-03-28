//Given an absolute path for a file (Unix-style), simplify it.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> way;
		int pos = 1, next;
		while (1) {
			next = path.find('/', pos);
			string s = path.substr(pos, next - pos);
			if (s == "..") {
				if (!way.empty()) {
					way.pop_back();
				}
			} else if (s != "." && s != "") {
				way.push_back(s);
			}
			if (next == string::npos) {
				break;
			}
			pos = next + 1;
		}
		if (way.empty()) {
			return "/";
		}
		string ret;
		for (auto i = way.begin(); i != way.end(); ++ i) {
			ret.append("/");
			ret.append(*i);
		}
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	string s;
	cin >> s;
	cout << sol.simplifyPath(s) << endl;
	return 0;
}
