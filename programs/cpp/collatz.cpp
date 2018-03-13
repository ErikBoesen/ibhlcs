#include <iostream>
#include <inttypes.h>

using namespace std;

void collatz(uint64_t x) {
    if (x <= 1) {
        cout << x << endl;
        return;
    } else cout << x << ", ";
    collatz((x & 0b1) ? (3*x+1) : (x/2));
}

int main() {
    uint64_t num;
    while (true) {
        cout << "> ";
        cin >> num;
        collatz(num);
    }
}
