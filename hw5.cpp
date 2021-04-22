#include <iostream>
#include <string>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::string;

//Convert your Triangle structure, and all your Triangle functions into a Triangle Class with methods. (each function will be a methods)
//Make use of Accessors, your Getters and Setters

class Triangle {
  private:
    float sA, sB, sC, angA, angB, angC, PI = 3.14159265, toDegrees = 180.;
  public:
    Triangle(float sideA, float sideB) {
      sA = sideA;
      sB = sideB;
    };

    Triangle(float sideA, float sideB, float angleA, float angleB) {
      sA = sideA;
      sB = sideB;
      angA = angleA;
      angB = angleB;
    };

    Triangle(float sideA, float sideB, float sideC, float angleA, float angleB, float angleC) {
      sA = sideA;
      sB = sideB;
      sC = sideC;
      angA = angleA;
      angB = angleB;
      angC = angleC;
    };

    float convertToDegrees() {
      return (toDegrees / PI);
    }

    float getSideA() {
      return sA;
    };

    float getSideB() {
      return sB;
    };

    float getAngleA() {
      return angA;
    };

    float getAngleB() {
      return angB;
    };

    float calculateHypotenuse() {
      float hypotenuse = sqrt(pow(sA, 2) + pow(sB, 2));
      return hypotenuse;
    };

    float calculateAngle(float side) {
      float hypo = calculateHypotenuse();
      float angX = asin(side / hypo) * convertToDegrees();
      return angX;
    };
};

int main() {
  Triangle tri1 = Triangle(3., 4.);
  cout << "Triangle 1 has a hypotenuse of : " << tri1.calculateHypotenuse() << " units." << endl;
  cout << "Theta 1 of Triangle 1 is " << tri1.calculateAngle(tri1.getSideA()) << " degrees." << endl;
  cout << "Theta 2 of Triangle 1 is " << tri1.calculateAngle(tri1.getSideB()) << " degrees." << endl;
  cout << endl;
  Triangle tri2 = Triangle(5., 12.);
  cout << "Triangle 1 has a hypotenuse of : " << tri2.calculateHypotenuse() << " units." << endl;
  cout << "Theta 1 of Triangle 2 is " << tri2.calculateAngle(tri2.getSideA()) << " degrees." << endl;
  cout << "Theta 2 of Triangle 2 is " << tri2.calculateAngle(tri2.getSideB()) << " degrees." << endl;
}
