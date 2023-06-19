#include <stdio.h>

#define EMPTY -1
#define MAX 20
#define SKIP 3

int hash(int x) { return x % MAX; }

int next(int x) {
    x = x + SKIP;
    return x % MAX;
}

void store(int *table, int d) {
    int h;
    h = hash(d);
    while (table[h] != EMPTY) h = next(h);
    table[h] = d;
}

int search(int *table, int d) {
    int h;
    h = hash(d);
    while (table[h] != EMPTY) {
        if (table[h] == d) return d;
        h = next(h);
    }
    return -1;
}

int main() {
    int i, query;
    int table[MAX];
    int data[] = {31, 45, 59, 25, 95, 39, 76, 27, 65, 43};

    /* 配列を初期化する */
    for (i = 0; i < MAX; i++) table[i] = EMPTY;

    /* 10個の非負整数を格納する */
    for (i = 0; i < 10; i++) store(table, data[i]);

    /* キーボードから非負整数を入力する */
    printf("Query: ");
    scanf("%d", &query);

    /* 入力された非負整数が配列に格納されているかどうかを調べる */
    if (search(table, query) != -1)
        printf("Found.\n");
    else
        printf("Not found.\n");

    return 0;
}