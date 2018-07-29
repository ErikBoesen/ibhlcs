// The best implementation of the Fizzbuzz problem, using bitwise operators.
#include <stdio.h>

int main() {
    char buf[4];
    char* arr[] = {
        buf,
        "Buzz",
        "Fizz",
        "Fizzbuzz",
    };
    for (unsigned i = 1; i <= 100; ++i) {
        sprintf(buf, "%u", i);
        puts(arr[!(i%5)|(!(i%3)<<1)]);
    }
}

