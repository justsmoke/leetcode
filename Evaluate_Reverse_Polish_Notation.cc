//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//Valid operators are +, -, *, /. Each operand may be an integer or another expression.
#include <vector>
#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		stack<int> formula;
		for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
			if (*it == "+") {
				int a = formula.top();
				formula.pop();
				int b = formula.top();
				formula.pop();
				formula.push(b + a);
			} else if (*it == "-") {
				int a = formula.top();
				formula.pop();
				int b = formula.top();
				formula.pop();
				formula.push(b - a);
			}
			else if (*it == "*") {
				int a = formula.top();
				formula.pop();
				int b = formula.top();
				formula.pop();
				formula.push(b * a);
			} else if (*it == "/") {
				int a = formula.top();
				formula.pop();
				int b = formula.top();
				formula.pop();
				formula.push(b / a);
			} else {
				stringstream ss;
				ss << *it;
				int i;
				ss >> i;
				formula.push(i);
			}
		}
		int ret = formula.top();
		formula.pop();
		return ret;
	}
};

int main() {
	Solution sol = Solution();
	string input[] = {"4", "13", "5", "/", "+"};
	vector<string> tokens(input, input + sizeof(input) / sizeof(string));
	cout << sol.evalRPN(tokens) << endl;
	return 0;
}
