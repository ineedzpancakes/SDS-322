#include <iostream>
using std::cout;
using std::endl;
#include <time.h>

int main() {
srand(time(NULL));
int headsCount = 0;
int tailsCount = 0;
int random;

for (int i = 0 ; i < 1000 ; i++) {
	random = rand();
	
	// Here we consider all even numbers as heads
	if (random % 2 == 0) {
		headsCount++;
	}
	// Here we consider all odd numbers as heads
	else if (random % 2 != 0) {
		tailsCount++;
	}
}
cout << "The total number of Heads is: " << headsCount << endl;
cout << "The total number of Tails is: " << tailsCount << endl;
}
