#include <iostream>
#include <cmath>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Point {
	private:
		float px, py;
	public:
		Point(float xcoordinate, float ycoordinate) {
			px = xcoordinate;
			py = ycoordinate;
		}

	float get_x() {
		return px;
	}

	float get_y() {
		return py;
	}

	float distance_to_origin() {
		return sqrt(pow(px, 2) + pow(py, 2));
	}

	float distance(Point point2) {
		float distance = sqrt(pow(px - point2.get_x(), 2) + pow(py - point2.get_y(), 2));
		return distance;
	}

	void printout() {
		cout << "(" << px << ", " << py << ")" << endl;
	}
};

class Line {
	private:
		float px1, py1, px2, py2;
	public:
		Line(Point p1, Point p2) {
			px1 = p1.get_x();
			py1 = p1.get_y();
			px2 = p2.get_x();
			py2 = p2.get_y();
		}

		Point midpoint() {
			float mx = (px1 + px2) / 2;
			float my = (py1 + py2) / 2;
			return Point(mx, my);
		}
		
		void printout() {
		cout << "Point 1: " << "(" << px1 << ", " << py1 << ")" << endl;
		cout << "Point 2: " << "(" << px2 << ", " << py2 << ")" << endl;
		}	
		
};

int main() {
	float x1 = 3.;
	float y1 = 4.;
	float x2 = 5.;
	float y2 = 12.;

	Point point1 = Point(x1, y1);
	Point point2 = Point(x2, y2);
	Line line = Line(point1, point2);

	line.printout();
	
	cout << endl;
	
	Point midpoint = line.midpoint();
	cout << "The midpoint for Point 1 and Point 2 is: ";
	midpoint.printout();
}
