#include <stdio.h>
#include <stdlib.h>
#define M 100
#define root 0

void exchange(int n, int *A) {
    int i, tmp;
    if (n == 0) return;
    i = (n - 1) / 2;
    if (A[i] > A[n]) {
        tmp = A[i];
        A[i] = A[n];
        A[n] = tmp;
        exchange(i, A);
    }
    return;
}

int insert(int x, int *A, int n) {
    if (n >= M || x <= 0) exit(1);
    A[n] = x;
    exchange(n, A);
    return ++n;
}

void inorder(int n, int *A) {
    if (n >= M) return;
    if (A[n] == -1) return;
    inorder(2 * n + 1, A);
    printf("%d ", A[n]);
    inorder(2 * n + 2, A);
}

int main() {
    int A[M];
    int i, n;
    for (i = 0; i < M; i++) A[i] = -1;
    n = 0;
    n = insert(3, A,
               insert(6, A, insert(2, A, insert(10, A, insert(11, A, n)))));
    inorder(root, A);
    return 0;
}