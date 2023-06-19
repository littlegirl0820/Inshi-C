#include <stdio.h>
#include <stdlib.h>
void swap(int d[], int p, int q) {
    int tmp;
    tmp = d[p];
    d[p] = d[q];
    d[q] = tmp;
}

void downh(int d[], int n, int k) {
    int child, current = k;
    while (current < n / 2) {
        child = 2 * current + 1;
        if ((child + 1 < n) && (d[child] < d[child + 1])) child++;
        if (d[current] < d[child])
            swap(d, current, child);
        else
            break;
        current = child;
    }
}
void uph(int d[], int k) {
    int parent, current = k;
    while (0 < current) {
        parent = (current - 1) / 2;
        if (d[parent] < d[current])
            swap(d, current, parent);
        else
            break;
        current = parent;
    }
}
void sort(int d[], int n) {
    int i;
    for (i = 1; i < n; i++) uph(d, i);
    for (i = n - 1; 0 < i; i--) {
        swap(d, 0, i);
        downh(d, i, 0);
    }
}

int main() {
    int i, N, *D;
    FILE* fp;
    fp = fopen("data.txt", "r");
    fscanf(fp, "%d\n", &N);
    D = (int*)malloc(sizeof(int) * N);
    for (i = 0; i < N; i++) fscanf(fp, "%d", &D[i]);
    fclose(fp);

    sort(D, N);

    for (i = 0; i < N; i++) printf("%d ", D[i]);
    printf("\n");
    free(D);
    return 0;
}