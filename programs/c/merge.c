#include <stdio.h>
#define LEN 10

void merge(int list[], int start, int middle, int end) {
    int b[LEN - 1];

    int left, right, i;

    for (left = start, right = middle + 1, i = start; left <= middle && right <= end; i++) {
        if (list[left] <= list[right]) b[i] = list[left++];
        else b[i] = list[right++];
    }

    while (left <= middle) b[i++] = list[left++];
    while (right <= end) b[i++] = list[right++];
    for (i = start; i <= end; i++) list[i] = b[i];
}

void sort(int list[], int start, int end) {
    if (end > start) {
        int middle = (start + end) / 2;
        sort(list, start, middle);
        sort(list, middle + 1, end);
        merge(list, start, middle, end);
    }
}

int main() {
    int X[LEN] = {3, 5, 1, 99, 3, 55, 0, 8, 45, 44};
    sort(X, 0, LEN);
    for (int i = 0; i < LEN; i++) printf("%d ", X[i]);
}
