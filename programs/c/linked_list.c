#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
};

int main() {
    node *pn;
    node *n;
    for (int i = 0; i < 10; i++) {
        node *n = {i, &pn};
        node pn = n;
    }
    printf("%d     ", pn.data);
    //for (n = pn; n.next != NULL; n = *(n.next)) {
        //printf("%x, ", n.data);
    //}
}
