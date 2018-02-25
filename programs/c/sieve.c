// Find sum of all prime numbers under LIMIT
#include <math.h>
#define LIMIT 1000000
int main() {
    char sieve[LIMIT];
    for (int i = 2; i < LIMIT; i++) sieve[i] = 1;
    for (int factor = 2; factor <= (int)sqrt(LIMIT); ++factor)
        for (int mult = 2; factor * mult < LIMIT; ++mult)
            sieve[factor * mult] = 0;
    long total = 2;
    for (int i = 3; i < LIMIT; i += 2) if (sieve[i]) total += i;
}
