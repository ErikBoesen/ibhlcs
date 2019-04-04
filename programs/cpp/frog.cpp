#include <iostream>
#include <stdlib.h>
#include <time.h>


class Frog {
private:
    int distance;
    int maxHops;
    int maxHopLength;
public:
    Frog(int distance, int maxHops, int maxHopLength) {
        this->distance = distance;
        this->maxHops = maxHops;
        this->maxHopLength = maxHopLength;
    };
    double simulate(int iterations) {
        int successes = 0;
        for (int iteration = 0; iteration < iterations; iteration++) {
            int traveled = 0;
            for (int i = 0; i < this->maxHops; i++) {
                traveled += rand() % this->maxHopLength;
            }
            if (traveled >= this->distance) {
                successes++;
            }
        }
        return (double)successes / iterations;
    };
};

int main() {
    srand(time(NULL));
    Frog frog(20, 5, 10);
    std::cout << frog.simulate(50) << std::endl;
}
