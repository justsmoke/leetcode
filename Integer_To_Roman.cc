//Given an integer, convert it to a roman numeral.
//Input is guaranteed to be within the range from 1 to 3999.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string s;
		int a = num / 1000;
		int b = (num % 1000) / 100;
		int c = (num % 100) / 10;
		int d = num % 10;
		if (a) {
			s.append(generate(a, ' ', 'M', ' '));
		}
		if (b) {
			s.append(generate(b, 'D', 'C', 'M'));
		}
		if (c) {
			s.append(generate(c, 'L', 'X', 'C'));
		}
		if (d) {
			s.append(generate(d, 'V', 'I', 'X'));
		}
		return s;
	}

	string generate(int digit, char big, char small, char higher) {
		string s;
		if (digit == 9) {
			s.append(1, small);
			s.append(1, higher);
		} else if (digit >= 5) {
			s.append(1, big);
			s.append(digit - 5, small);
		} else if (digit < 4) {
			s.append(digit, small);
		} else {
			s.append(1, small);
			s.append(1, big);
		}
		return s;
	}
};

int main() {
	Solution sol = Solution();
	int num;
	while (cin >> num) {
		cout << sol.intToRoman(num) << endl;
	}
	return 0;
}
