//Implement atoi to convert a string to an integer.

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
	int atoi(const char *str) {
		while (*str == ' ') {
			++ str;
		}
		int sign = 1;
		if (*str == '-') {
			sign = -1;
			++ str;
		}
		if (*str == '+') {
			++ str;
		}
		int ret = 0;
		while (*str != '\0') {
			if (*str < '0' || *str > '9') {
				return sign * ret;
			}
			int d = *str - '0';
			if (sign == 1 && (ret > INT_MAX/10 || (ret == INT_MAX/10 && d > INT_MAX%10))) {
				return INT_MAX;
			}
			if (sign == -1 && (ret > -(INT_MIN/10) || (ret == -(INT_MIN/10) && d > -(INT_MIN%10)))) {
				return INT_MIN;
			}
			ret = ret * 10 + d;
			++ str;
		}
		return sign * ret;
	}
};

int main() {
	Solution sol = Solution();
	cout << sol.atoi("-2147483649") << endl;
	return 0;
}
