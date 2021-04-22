#include <iostream>
#include <string>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::string;


//Define a triangle struct that has 3 float sides and 3 float angles.
//Write a program that sets 2 side lengths (hard coded) for two (2) separate triangles,
//and computes and outputs the hypotenuse, 90 degree angle, Theta 1 angle, and Theta 2 angle for each of the triangles.

//Triangle 1 sides = 3,4
//Traingle 2 sides = 5,12

//Specifications: Your functions will now use your struct as a parameter to make the calculations.
//The triangle should be a custom datatype with six (6) floats that are all either given or calculated and output (cout) from the custom datatype.

struct triangle {
  float sideA;
  float sideB;
  float sideC;
  float sideX;

  float angleA;
  float angleB;
  float angleC;
};

float calculateHypotenuse(triangle a, triangle b);
float calculateAngle1(triangle side_a, triangle hypo);
float calculateAngle2(triangle side_b, triangle hypo);

int main() {
  // side lendths of each triangle
  triangle a1, b1, c1;
  triangle a2, b2, c2;

  // angles of each triangle
  triangle A1, B1, C1;
  triangle A2, B2, C2;

  // Triangle 1 hypotenuse
  a1.sideA = 3;
  b1.sideB = 4;
  c1.sideC = calculateHypotenuse(a1, b1);
  cout << "Triangle 1 has a hypotenuse of " << c1.sideC << " units."  << endl;

  // Triangle 1 angles
  A1.angleA = calculateAngle1(a1, c1);
  B1.angleB = calculateAngle2(b1, c1);
  C1.angleC = A1.angleA + B1.angleB;
  cout << "Theta 1 of Triangle 1 is " << A1.angleA << " degrees." << endl;
  cout << "Theta 2 of Triangle 1 is " << B1.angleB << " degrees." << endl;
  cout << "Theta 1 + Theta 2 is equal to " << C1.angleC << " degrees." << endl;
  cout << endl;

  /////////////////////////////////////////////////////////////////////////////

  // Triangle 2 hypotenuse
  a2.sideA = 5;
  b2.sideB = 12;
  c2.sideC = calculateHypotenuse(a2, b2);
  cout << "Triangle 2 has a hypotenuse of " << c2.sideC << " units."  << endl;

  // Triangle 1 angles
  A2.angleA = calculateAngle1(a2, c2);
  B2.angleB = calculateAngle2(b2, c2);
  C2.angleC = A2.angleA + B2.angleB;
  cout << "Theta 1 of Triangle 2 is " << A2.angleA << " degrees." << endl;
  cout << "Theta 2 of Triangle 2 is " << B2.angleB << " degrees." << endl;
  cout << "Theta 1 + Theta 2 is equal to " << C2.angleC << " degrees." << endl;

}

float calculateHypotenuse(triangle side_a, triangle side_b) {
  float hypotenuse = sqrt(pow(side_a.sideA, 2) + pow(side_b.sideB, 2));
  return hypotenuse;
}

float calculateAngle1(triangle side_a, triangle hypo) {
  float PI = 3.14159265;
  float angX = asin(side_a.sideA / hypo.sideC) * (180 / PI);
  return angX;
}

float calculateAngle2(triangle side_b, triangle hypo) {
  float PI = 3.14159265;
  float angX = asin(side_b.sideB / hypo.sideC) * (180 / PI);
  return angX;
}
