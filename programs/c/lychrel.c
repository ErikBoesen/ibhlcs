#include <stdio.h>
#include <math.h>

#define RANGE 20000

int digof(int x, int n) { return (x % (int)pow(10, n+1)) / (int)pow(10, n); }
int digcount(int x) { return (int)log10(x) + 1; }

int reverse(int x) {
    int y = 0, len = digcount(x);
    for (int i = 0; i < len; i++) y += digof(x, len - i - 1) * pow(10, i);
    return y;
}

int is_palindrome(int x) { return reverse(x) == x; }

int is_lychrel(int x) {
    while (0 < x) {
        if (is_palindrome(x)) {
#ifdef DEBUG
            printf("%d is a valid Lychrel number!\n", x);
#endif
            return 1;
        }
#ifdef DEBUG
        printf("%d is not a palindrome, trying ", x);
#endif
        x += reverse(x);
#ifdef DEBUG
        printf("%d\n", x);
#endif
    }
    return 0;
}

int main() {
    int total = 0;
    for (int num = 0; num < RANGE; num++) if (is_lychrel(num)) total++;
    printf("%d", total);
}
