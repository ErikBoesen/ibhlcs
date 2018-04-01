// A simple program for demonstrating the basic idea of genetic algorithms by converging to a single number.

#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>

#define MEMBERS 10
#define LIMIT 10000
#define TARGET 3422
// Momentum
#define ALPHA 10
#define GENERATIONS 50

using namespace std;

int fitness(int member) {
    // This is where one would normally do any complex calculations needed
    // to determine a member's fitness. For this example, we just want to know
    // how far the number is from the target.
    return abs(member - TARGET);
}

int random_shift(int alpha) {
    return rand() % (2*alpha) - alpha;
}

int mutate(int member) {
    return
            // Original value
            member +
            // Random shift in either direction
            random_shift(ALPHA);
}

int main() {
    srand(time(NULL));
    cout << "Target: " << TARGET << endl;
    vector<int> population;
    for (int i = 0; i < MEMBERS; i++) population.push_back(rand() % LIMIT);
    for (int generation = 0; generation < GENERATIONS; generation++) {
        cout << endl << "Generation #" << generation << endl;
        cout << "Initial population: ";
        for (int i = 0; i < MEMBERS; i++) cout << population[i] << ' ';
        cout << endl;
        int fittest;
        for (int i = 0; i < MEMBERS; i++) {
            if (fitness(population[i]) < fitness(fittest)) fittest = population[i];
        }
        population.clear();
        population.push_back(fittest);
        cout << "Fittest: " << fittest << " (fitness " << fitness(fittest) << ")" << endl;
        for (int i = 1; i < MEMBERS; i++) population.push_back(mutate(fittest));
    }
}
