#include <stdbool.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int* sequence;

uint64_t fib(int index) {
    if (index <= 1) return index;
    if (!sequence[index]) {
        sequence[index] = fib(index - 1) + fib(index - 2);
    }
    return sequence[index];
}

int main(int argc, char* argv[]) {
    if (argc < 1) {
        printf("Not enough arguments!\n");
        exit(1);
    }
    uint64_t index = atoll(argv[1]);
    sequence = (int*)malloc(index * sizeof(int));
    for (int i = 0; i < index; i++) {
        sequence[i] = 0;
    }
    printf("%llu\n", fib(index));
    free(sequence);
}
