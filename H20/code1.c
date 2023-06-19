#include <stdio.h>
#define MAX 32

typedef struct item {
    int key;
    float info;
} Item;

void merge(Item *A, int nA, Item *B, int nB, int i, Item *C) {
    int iA, iB, iC;
    iA = iB = iC = 0;
    while (iC <= nA + nB - 1) {
        if (iA >= nA)
            C[i + iC] = B[iB++]; /* Aについては終了 */
        else if (iB >= nB)       /* Bについては終了 */
            C[i + iC] = A[iA++];
        else if (A[iA].key <= B[iB].key)
            C[i + iC] = A[iA++];
        else
            C[i + iC] = B[iB++];
        iC = iC + 1;
    }
}

void msort(int first, int last, Item *A) {
    int i, j, middle;
    Item A1[MAX], A2[MAX];

    if (last - first < 1) return;
    middle = (first + last) / 2; /* 中央値により分割 */
    msort(first, middle, A);     /* 前半の整列 */
    msort(middle + 1, last, A);  /* 後半の整列 */

    i = first;
    j = 0;
    while (i < middle + 1) A1[j++] = A[i++]; /* A1は前半の部分配列 */
    i = middle + 1;
    j = 0;
    while (i < last + 1) A2[j++] = A[i++]; /* A2は後半の部分配列 */
    merge(A1, middle - first + 1, A2, last - middle, first, A); /* 併合 */
}

void print_array(int first, int last, Item *A) {
    int k;
    for (k = first; k < last + 1; k++)
        printf("%d: %d, %3.1f\n", k, A[k].key, A[k].info);
}

Item X[] = {{5, 2.0}, {8, 3.5}, {2, 4.5}, {7, 5.0},
            {2, 6.5}, {3, 9.0}, {4, 8.0}, {3, 7.5}};

int main() {
    msort(0, 7, X);
    print_array(0, 7, X);
    return 0;
}