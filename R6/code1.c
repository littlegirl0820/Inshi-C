#include <stdio.h>
#include <stdlib.h>

void sort(int array[], int n) {
    int i, j, key, target;

    for (i = 1; i < n; i++) {
        key = array[i];
        for (j = 0; j < i; j++) {
            if (array[j] > key) {
                break;
            }
        }
        target = j;

        for (j = i - 1; j >= target; j--) {
            array[j + 1] = array[j];
        }
        array[target] = key;
    }
}

int main(void) {
    int N, i;
    FILE *fp;
    int *data;

    fp = fopen("data.txt", "r");
    fscanf(fp, "%d", &N);
    data = (int *)malloc(sizeof(int) * N);
    for (i = 0; i < N; i++) {
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);

    sort(data, N);

    for (i = 0; i < N; i++) {
        printf("%d\n", data[i]);
    }
    free(data);
    return 0;
}