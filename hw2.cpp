#include <iostream>
#include <string>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// NOTE: Hardcode in side A = 3 and side B = 4
//Write a program that from two lengths of a right triangle calculates the hypotenuse and the two adjacent angles. 
//The hypotenuse function, and each angle function should all be separate functions.  Hint: Don't forget to return the answers from the functions.

double calculateHypotenuse(double a, double b);
double calculateAngle(double x, double hypotenuse);

int main() {
  double side_a = 3;
  double side_b = 4;

  cout << "With a side a of " << side_a << " and a side b of " << side_b << endl;

  double hypo = calculateHypotenuse(side_a, side_b);
  cout << "The hypotenuse is = " << hypo << endl;

  double angle_A = calculateAngle(side_a, hypo);
  double angle_B = calculateAngle(side_b, hypo);

   cout << "The angle 1 is = " << angle_A << " degrees" << endl;
   cout << "The angle 2 is = " << angle_B << " degrees" << endl;
}

double calculateHypotenuse(double a, double b) {
  double hypotenuse = sqrt(pow(a, 2) + pow(b, 2));
  return hypotenuse;
}

double calculateAngle(double x, double hypotenuse) {
  double PI = 3.14159265;
  double angX = asin(x / hypotenuse) * (180 / PI);
  return angX;
}
