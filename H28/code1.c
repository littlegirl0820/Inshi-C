#include <stdio.h>
#define MAXR 256
#define MAXN 1000
void sort(int values[], int numvalues, int r, int maxdigit) {
    int rd, d, b, i, n, j;
    int buckets[MAXR][MAXN];
    int numbucket[MAXR];

    rd = 1;
    for (d = 1; d <= maxdigit; d++) {
        for (b = 0; b < r; b++) {
            numbucket[b] = 0;
        }
        for (i = 0; i < numvalues; i++) {
            n = (values[i] / rd) % r;
            buckets[n][numbucket[n]++] = values[i];
        }

        i = 0;
        for (b = 0; b < r; b++) {
            for (j = 0; j < numbucket[b]; j++) {
                values[i++] = buckets[b][j];
            }
        }
        rd *= r;
    }
}
int main() {
    int i;
    int values[5] = {12, 21, 1, 11, 2};

    sort(values, 5, 10, 2);
    for (i = 0; i < 5; i++) {
        printf("%d\n", values[i]);
    }
    return 0;
}