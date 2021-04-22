#include <iostream>
#include <string>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// Write a program that asks the user for sets the length of side a = 3 and side b = 4. 
//From those two (2) variables calculate the hypotenuse, angle A (𝛳1), and angle B (𝛳2) for a right triangle. [Hint: For the angles SOHCAHTOA]
int main() {
  double side_a;
  double side_b;
  double PI = 3.14159265;

  cout << "Enter side a value\n";
  cin >> side_a;

  cout << "Enter side b value\n";
  cin >> side_b;

  cout << "With a side a of " << side_a << " and a side b of " << side_b << endl;
  
  double hypotenuse = sqrt(pow(side_a, 2) + pow(side_b, 2));

  cout << "The hypotenuse is = " << hypotenuse << endl;

  double angle_A = asin(side_a / hypotenuse) * (180 / PI);
  double angle_B = asin(side_b / hypotenuse) * (180 / PI);

   cout << "The angle 1 is = " << angle_A << " degrees" << endl;
   cout << "The angle 2 is = " << angle_B << " degrees" << endl;
}
