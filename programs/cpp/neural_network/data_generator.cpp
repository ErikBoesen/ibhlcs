#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
	// Create training set for teaching the network how to XOR numbers.

	cout << "topology: 2 5 1" << endl;
	for (int i = 40; i >= 0; --i) {
		int n1 = (int)(2.0 * rand() / double(RAND_MAX));
		int n2 = (int)(2.0 * rand() / double(RAND_MAX));
		int t = n1 ^ n2; // should be 0 or 1
		cout << "in: " << n1 << ".0 " << n2 << ".0 " << endl;
		cout << "out: " << t << ".0" << endl;
	}
}
