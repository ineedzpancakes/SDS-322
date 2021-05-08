#include <iostream>
#include <string>
#include <cmath>
using std::cout;
using std::endl;
using std::string;

double calculateHypoAndAngles(int a, int b);

int main() {
double sideA = 3;
double sideB = 4;

cout << "With a side a of " << sideA << " and a side b of " << sideB << endl;
calculateHypoAndAngles(sideA, sideB);

}

double calculateHypoAndAngles(int a, int b) {
double hypotenuse = sqrt(pow(a, 2) + pow(b, 2));
cout << "The hypotenuse is = " << hypotenuse << endl;

double PI = 3.14159265;
double angleA = asin(a / hypotenuse) * (180 / PI);
double angleB = asin(b / hypotenuse) * (180 / PI);

cout << "The angle 1 is = " << angleA << " degrees" << endl;
cout << "The angle 2 is = " << angleB << " degrees" << endl;
return 0;
}
