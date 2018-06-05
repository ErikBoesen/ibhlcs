// Find first number which, when you take the largest digit and place it at the end, is half the original number.
#include <stdio.h>
#include <math.h>
#include <inttypes.h>

#define BASE 10

uint8_t numdigits(uint64_t x) {
    uint8_t count;
    while (x != 0) {
        x /= BASE;
        ++count;
    }
    return count;
}
// TODO: Type conversion overdone?
int digof(uint64_t x, uint8_t n) { return (uint64_t)(x % (int)pow(BASE, n+1)) / (int)pow(BASE, n); }

uint64_t convert(uint64_t x) {
    int n = numdigits(x);
    int nth = digof(x, n - 1);
    x -= pow(BASE, n - 1) * nth;
    x *= BASE;
    x += nth;
    return x;
}

int works(uint64_t x) {
    return (2 * convert(x) == x);
}

int main(int argc, char *argv[]) {
    uint64_t x = 1;
    for (; !works(x); ++x);
    printf("%llu\n", x);
    return 0;
}
