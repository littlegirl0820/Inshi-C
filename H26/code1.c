#include <stdio.h>
#include <stdlib.h>

int front = 0;
int rear = 0;

void insert(int A[], int SIZE, int d) {
    int p, left, right, m, i;
    if (rear > SIZE - 1) {
        printf("Overflow !!\n");
        exit(1);
    }

    p = -1;
    if (front == rear)
        p = front;
    else {
        left = front;
        right = rear - 1;
        while (left < right) {
            m = (left + right) / 2;
            if (A[m] == d) {
                p = m + 1;
                break;
            }
            if (d < A[m])
                right = m - 1;
            else
                left = m + 1;
        }
        if (p == -1) {
            if (A[left] > d)
                p = left;
            else
                p = left + 1;
        }
    }

    i = rear;
    while (i > p) {
        A[i] = A[i - 1];
        i--;
    }
    A[p] = d;
    rear++;
}

int delete(int A[]) {
    int x;
    if (front == rear) {
        printf("Underflow !!\n");
        exit(1);
    }
    x = A[front];
    front++;
    return x;
}

int main() {
    int i;
    int A[20];
    int SIZE = 20;

    int a1[5] = {10, 5, 20, 6, 13};
    int a2[5] = {2, 5, 18, 7, 5};

    for (i = 0; i < 5; i++) insert(A, SIZE, a1[i]);
    for (i = 0; i < 3; i++) {
        printf("%d ", delete (A));
        printf("\n");
    }

    for (i = 0; i < 5; i++) insert(A, SIZE, a2[i]);
    for (i = 0; i < 7; i++) {
        printf("%d ", delete (A));
        printf("\n");
    }

    return 0;
}