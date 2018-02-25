// Using XOR swap to swap two integers
#include <stdio.h>

void swap(int *restrict x, int *restrict y) {
    if (x != y) {
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
}

int main() {
    int x = 2;
    int y = 3;
    printf("%d %d\n", x, y);
    swap(&x, &y);
    printf("%d %d\n", x, y);
}
