#include <iostream>

using namespace std;

void collatz(int x) {
    if (x <= 1) {
        cout << x << endl;
        return;
    } else cout << x << ", ";
    collatz((x & 0b1) ? (3*x+1) : (x/2));
}

int main() {
    int num;
    while (true) {
        cout << "> ";
        cin >> num;
        collatz(num);
    }
}
