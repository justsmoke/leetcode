//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
#include <vector>
#include <iostream>
#include <map>
#include <cstdlib>
#include <sstream>

using namespace std;

struct Point {
	int x;
	int y;
	Point(): x(0), y(0) {}
	Point(int a, int b): x(a), y(b) {}
};

class Solution {
public:
	int gcd(int i, int j) {
		return i ? gcd(j % i, i) : j;
	}

	int maxPoints(vector<Point> &points) {
		int max = 0;
		for (vector<Point>::iterator i = points.begin(); i != points.end(); ++i) {
			int x1 = i->x, y1 = i->y;
			int same = 1;
			int vertical = 0;
			map<string, int> line;
			for (vector<Point>::iterator j = i + 1; j != points.end();) {
				int x2 = j->x, y2 = j->y;
				if (x1 == x2 && y1 == y2) {
					same += 1;
					j = points.erase(j);
				} else if (x1 == x2 && y1 != y2) {
					vertical += 1;
					++j;
				} else {
					int xdiff = x1 - x2, ydiff = y1 - y2;
					int d = gcd(abs(xdiff), abs(ydiff));
					xdiff = xdiff / d;
					ydiff = ydiff / d;
					if (xdiff < 0) {
						xdiff = -xdiff;
						ydiff = -ydiff;
					}
					stringstream ss;
					ss << xdiff << "#" << ydiff;
					string s;
					ss >> s;
					line[s] += 1;
					++j;
				}
			}
			int m = vertical;
			for (map<string, int>::iterator it = line.begin(); it != line.end(); ++it) {
				if (it->second > m) {
					m = it->second;
				}
			}
			m += same;
			m > max ? max = m : 1;
		}
		return max;
	}
};

int main() {
	Solution sol = Solution();
	Point pointArray[] = {Point(1,1), Point(1,1), Point(1,2), Point(1,3), Point(2,2), Point(3,3), Point(4,4)};
	vector<Point> points(pointArray, pointArray + sizeof(pointArray) / sizeof(Point));
	cout << sol.maxPoints(points) << endl;
	return 0;
}
