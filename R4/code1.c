#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int score;
} user_t;

void swap(user_t* A, user_t* B) {
    user_t tmp = *A;
    *A = *B;
    *B = tmp;
}

void sort(user_t D[], int left, int right) {
    if (left < right) {
        int j, i = left;
        user_t pivot = D[right];
        for (j = left; j < right; j++) {
            if (D[j].score > pivot.score) {
                swap(&D[i], &D[j]);
                i++;
            }
        }
        swap(&D[i], &D[right]);
        sort(D, left, i - 1);
        sort(D, i + 1, right);
    }
}

int main() {
    int i, N;
    user_t* D;
    FILE* fp = fopen("data.txt", "r");
    fscanf(fp, "%d", &N);
    D = (user_t*)malloc(sizeof(user_t) * N);
    for (i = 0; i < N; i++) {
        fscanf(fp, "%d %d", &D[i].id, &D[i].score);
    }
    fclose(fp);
    sort(D, 0, N - 1);
    for (i = 0; i < N; i++) {
        printf("%d %d\n", D[i].id, D[i].score);
    }
    free(D);
    return 0;
}