#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int fib(int index) {
    if (index <= 1) return index;
    else return fib(index - 1) + fib(index - 2);
}

int main(int argc, char *argv[]) {
    if (argc < 1) {
        printf("Not enough arguments!\n");
        exit(1);
    }
    unsigned long long index = atoll(argv[1]);
    printf("%llu\n", fib(index));
}
