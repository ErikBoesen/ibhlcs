// Find first number which, when you take the largest digit and place it at the end, is half the original number.
// BROKEN
#include <stdio.h>
#include <math.h>
#include <inttypes.h>

#define DEBUG
#define BASE 10
#define BASETENANS 105263157894736842

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
#ifdef DEBUG
    printf("n/nth: %d %d\n", n, nth);
#endif
#ifdef DEBUG
    printf("%llu converts to ", x);
#endif
    x -= pow(BASE, n - 1) * nth;
    x *= BASE;
    x += nth;
#ifdef DEBUG
    printf("%llu\n", x);
#endif
    return x;
}

int works(uint64_t x) {
    return ((2 * convert(x)) == x);
}

int main(int argc, char *argv[]) {
    printf("%d\n", numdigits(105263157894736842ull));
    printf("%llu %llu\n", 105263157894736842ull, convert(105263157894736842));

    /*uint64_t x = BASETENANS - 10;
    for (; !works(x); ++x) {
        //printf("Trying %llu\n", x);
        if (x > BASETENANS + 30) break;
    }
    printf("%llu\n", x);*/
    return 0;
}
