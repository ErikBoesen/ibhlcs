#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>

#define BASE 2

using namespace std;

vector<int> radix(vector<int> v) {
    vector<int> buc[BASE];
    for (int max = *max_element(v.begin(), v.end()), expo = 0; BASE * expo <= max; expo++) {
        int divisor = pow(BASE, expo);
        for (int n : v) buc[(n / divisor) % BASE].push_back(n);
        v.clear();
        for (int i = 0; i < BASE; i++) {
            v.insert(v.end(), buc[i].begin(), buc[i].end());
            buc[i].clear();
        }
    }
    return v;
}

int main() {
    int arr[10];
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) arr[i] = rand() % 1000;
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    v = radix(v);

    for (int i : v) cout << i << " ";
    cout << endl;
}
