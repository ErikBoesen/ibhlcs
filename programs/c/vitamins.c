#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <inttypes.h>

#define NUM_VITAMINS 600
#define TOTAL_DOSAGE 4

#define RED 1
#define BLUE 2
#define EMPTY 0
// You like blue

int main() {
    srand(time(NULL));

    uint8_t bottle[NUM_VITAMINS];
    for (short i = 0; i < NUM_VITAMINS / 2; i++) bottle[i] = RED;
    for (short i = NUM_VITAMINS / 2; i < NUM_VITAMINS; i++) bottle[i] = BLUE;

    int vitamins_kept,
        blue = 0,
        red = 0,
        satisfactory = 0;
    for (int day = 0; day < NUM_VITAMINS / TOTAL_DOSAGE; day++) {
        for (int i = 0; vitamins_kept < TOTAL_DOSAGE; i++) {
            printf("%d\n", (rand() % NUM_VITAMINS));
            switch (bottle[rand() % NUM_VITAMINS]) {
                case EMPTY:
                    break;
                case RED:
                    vitamins_kept++;
                    red++;
                    break;
                case BLUE:
                    vitamins_kept++;
                    blue++;
                    break;
            }
        }
        if (vitamins_kept >= 2) vitamins_kept = 2;
        satisfactory += vitamins_kept;
        vitamins_kept = 0;
    }
    printf("red %d, blue %d\n", red, blue);
    printf("%.8f\n", (double)(satisfactory / NUM_VITAMINS));

    return 0;
}
