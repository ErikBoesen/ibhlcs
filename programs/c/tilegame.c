#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4
#define M 4

enum Move {UP, DOWN, LEFT, RIGHT};
int hR;
int hC;
int board[N][M];
const int nS = 100;

int update(enum Move m) {
    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};
    int i = hR+dy[m];
    int j = hC+dx[m];
    if (i >= 0 && i<N && j >= 0 && j < M) {
        board[hR][hC] = board[i][j];
        board[i][j] = 0;
        hR=i;
        hC=j;
        return 1;
    }
    return 0;
}
void setup() {
    int i, j, k;
    for (i = 0; i < N; i++) for (j = 0; j<M; j++) board[i][j]=i*M+j+1;
    board[N-1][M-1] = 0;
    hR = N-1;
    hC = M-1;
    k = 0;
    while(k < nS) k += update((enum Move)(rand()%4));
}
int isEnd() {
    int i, j;
    int k = 1;
    for(i = 0; i < N; i++) for(j = 0; j < M; j++) if (k < N*M && board[i][j] != k++) return 0;
    return 1;
}
void show() {
    int i, j;
    putchar('\n');
    for (i = 0; i < N; i++) for (j = 0; j < M; j++) {
        if (board[i][j]) printf(j != M-1 ? " %2d " : " %2d \n", board[i][j]);
        else printf(j != M-1 ? " %2s " : " %2s \n", "");
    }
    putchar('\n');
}
enum Move get() {
    int c;
    while (1) {
        printf("Enter direction (ULDR): ");
        c = getchar();
        while (getchar() != '\n');
        switch(c) {
            case 27:
                exit(0);
            case 'D':
            case 'd':
                return UP;
            case 'U':
            case 'u':
                return DOWN;
            case 'R':
            case 'r':
                return LEFT;
            case 'L':
            case 'l':
                return RIGHT;
            }
        }
}
void pause() {
    getchar();
}
int main() {
    srand((unsigned)time(NULL));
    setup();
    show();
    while (!isEnd()) {
        update(get());
        show();
    }
    printf("YOURE WINNER");
    pause();
    return 0;
}
