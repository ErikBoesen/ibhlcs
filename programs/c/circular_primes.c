#include <stdio.h>
#include <math.h>
#define LIMIT 1000000
#define BASE 10

char sieve[LIMIT];
void constructSieve() {
    for (int i = 2; i < LIMIT; i++) sieve[i] = 1;
    for (int factor = 2; factor <= (int)sqrt(LIMIT); ++factor)
        for (int mult = 2; factor * mult < LIMIT; ++mult)
            sieve[factor * mult] = 0;
}

int countDigits(int x) {
    int count = 0;
    while (x != 0) {
        x /= BASE;
        ++count;
    }
    return count;
}
int rotate(int x) {
    int end = x % BASE;
    x /= BASE;
    x += pow(BASE, countDigits(x)) * end;
    return x;
}
int check(int x) {
    int digits = countDigits(x);
    for (int n = x, iterations = 0; iterations < digits; ++iterations) {
        if (!sieve[n]) return 0;
        n = rotate(n);
    }
    return 1;
}

int main() {
    int count = 0;
    constructSieve();
    for (int x = 2; x < LIMIT; ++x) {
        if (check(x)) {
            printf("%d is a circular prime.\n", x);
            ++count;
        }
    }
    printf("There are %d circular primes under %d.\n", count, LIMIT);
}
