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

int main() {
	float x1 = 3.;
	float y1 = 4.;
	float x2 = 5.;
	float y2 = 12.;

	Point point1 = Point(x1, y1);
	cout << "Point 1: ";
	point1.printout();
	cout << "Distance from origin for Point 1: " << point1.distance_to_origin() << " units." << endl;
	
	cout << endl;

	Point point2 = Point(x2, y2);
	cout << "Point 2: ";
	point2.printout();
	cout << "Distance from origin for Point 2: " << point2.distance_to_origin() << " units." << endl;
	
	cout << endl;
	
	cout << "Distance between Point 1 and Point 2: ";
	cout << point1.distance(point2) << " units." << endl;

}
