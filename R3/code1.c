#include <stdio.h>
#include <stdlib.h>
#define NMAX 256

int qd[NMAX], qhead, qtail;

void printqueue(void) {
    int i;
    for (i = qhead; i != qtail; i = (i + 1) % NMAX) printf("p %d\n", qd[i]);
}

void enqueue(int d) {
    if ((qtail + 1) % NMAX != qhead) {
        qd[qtail] = d;
        qtail = (qtail + 1) % NMAX;
    } else
        exit(1);
}

void dequeue(void) {
    int i;
    if (qhead != qtail) {
        printf("d %d\n", qd[qhead]);
        qhead = (qhead + 1) % NMAX;
    } else
        exit(1);
}

int main(void) {
    FILE* fp;
    int n, i, d;

    qhead = 0, qtail = 0;
    fp = fopen("qdata.txt", "r");
    fscanf(fp, "%d\n", &n);
    for (i = 0; i < n; i++) {
        fscanf(fp, "%d\n", &d);
        if (d == 0)
            dequeue();
        else if (d > 0)
            enqueue(d);
    }
    fclose(fp);
    printqueue();
    return 0;
}