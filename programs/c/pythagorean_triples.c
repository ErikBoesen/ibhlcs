#include <stdio.h>
#include <time.h>

#define LIMIT 1000

int main() {
    int a = 0,
        b = 0,
        c = 0;

    int n = 2;

    do {
        for (int i = 1; i < n; ++i) {
            a = n*n - i*i;
            b = 2*n * i;
            c = n*n + i*i;

            if (a + b + c == LIMIT) break;
        }
        n++;
    } while (a + b + c != LIMIT);
    printf("%d", a * b * c);
}
