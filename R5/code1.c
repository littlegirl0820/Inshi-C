#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 20
#define TABLE1_SIZE 20
#define TABLE2_SIZE 10
#define EMPTY -1

int* search1(int* array, int size, int delta, int key);
int* search2(int* array1, int* array2, int size, int delta, int key);

int hash(int x, int n) { return x % n; }

void insert1(int* array, int size, int delta, int key) {
    int v = key;
    int h = hash(v, size);
    while (array[h] != EMPTY) {
        v += delta;
        h = hash(v, size);
    }
    array[h] = key;
}

int insert2_internal(int* array, int key, int h) {
    if (array[h] == EMPTY) {
        array[h] = key;
        return EMPTY;
    } else {
        int tmp = array[h];
        array[h] = key;
        return tmp;
    }
}

void insert2(int* array1, int* array2, int size, int delta, int key) {
    int x = key;
    while (1) {
        if ((x = insert2_internal(array1, x, hash(x, size))) == EMPTY) return;
        if ((x = insert2_internal(array2, x, hash(x ^ delta, size))) == EMPTY)
            return;
    }
}

int main() {
    FILE* fp;
    int i;
    int m;
    int delta;
    int table1[TABLE1_SIZE];
    int table2_1[TABLE2_SIZE];
    int table2_2[TABLE2_SIZE];
    int keys[MAX_KEYS];

    for (i = 0; i < TABLE1_SIZE; ++i) table1[i] = EMPTY;
    for (i = 0; i < TABLE1_SIZE; ++i) {
        table2_1[i] = EMPTY;
        table2_2[i] = EMPTY;
    }
    
    fp = fopen("input.txt", "r");
    fscanf(fp, "%d\n", &delta);
    fscanf(fp, "%d\n", &m);
    for (i = 0; i < m; ++i) fscanf(fp, "%d\n", &keys[i]);
    fclose(fp);
    for (i = 0; i < m; ++i) insert1(table1, TABLE1_SIZE, delta, keys[i]);

    for (i = 0; i < m; ++i)
        insert2(table2_1, table2_2, TABLE2_SIZE, delta, keys[i]);
    return 0;
}