#include <iostream>
#include <time.h>
#include <random>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main() {
  srand((unsigned)time(0));
  float random;
  vector<long long> get42(1);
  int index = 0;
  while (true) {
    random = 42. * rand() / RAND_MAX;
    if ((int) random == 42) {
      get42[index] = (int) random;
      break;
    }
    else {
      get42[index] = (int) random;
      get42.push_back(1);
      index++;
    }
  }
  int size = get42.size();
  cout << size << endl;
}