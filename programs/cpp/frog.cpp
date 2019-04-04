#include <iostream>


class Frog {
private:
    int maxHop;
    int end;
    int distance;
    int hop;
    bool simulate;
public:
    Frog(int distance, int maxHop) {
        this.distance = distance;
        this.maxHop = maxHop;
    };
    double runSimulation(int amount) {
    }
}

int main() {
    Frog frog = new Frog(20, 5);

}
