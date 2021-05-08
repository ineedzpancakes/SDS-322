#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

struct point {
	float x;
	float y;
};

struct line_segment {
	point p1;
	point p2;
};

float calc_distance(line_segment line);

int main() {
	point c1, c2;
	line_segment l;
	c1.x = 3.;
	c1.y = 4.;
	c2.x = 2.;
	c2.y = 2.;
	l.p1.x = c1.x;
	l.p1.y = c1.y;
	l.p2.x = c2.x;
	l.p2.y = c2.y;
	
	float dist = calc_distance(l);
	cout << dist << endl;
}

float calc_distance(line_segment line) {
	return sqrt(pow(line.p2.x - line.p1.x, 2) + pow(line.p2.y - line.p1.y, 2));
}
