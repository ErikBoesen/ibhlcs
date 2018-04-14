#include <stdio.h>

typedef struct {
    char* name;
    int age;
    long phone_number;
} Person;

typedef struct {
    unsigned int a:1;
    unsigned int b:2;
} bits;

enum states {NO, ATTEMPT, YES};

int main() {
    Person erik = {"Erik Boesen", 17, 0xBAE1E55};
    printf("%s tiene %d años, y su numero es %ld.\n", erik.name, erik.age, erik.phone_number);

    int a = ATTEMPT;
    printf("%d\n", a);

    bits b = {0, 0};
    for (int i = 0; i < 10; i++) {
        printf("%d %d / ", b.a, ++b.b);
    }
}
