#include <stdio.h>

void swap(int x, int y, int *key, int *label) {
    int temp;
    temp = key[x];
    key[x] = key[y];
    key[y] = temp;

    temp = label[x];
    label[x] = label[y];
    label[y] = temp;
}
void sort(int a, int b, int *key, int *label) {
    int i, j, skip = 1;

    for (i = a; i < b; i++) {
        skip = b - i;
        for (j = b; j > i; j--) {
            if (key[j] < key[j - 1]) {
                swap(j, j - 1, key, label);
                skip = j - i;
            }
        }
        printf("%d\n", skip);
    }
}
int main() {
    int key[] = {1, 1, 2, 5, 4, 5, 2, 6, 3, 4, 3, 6};
    int label[] = {1, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2};
    int n = 12;

    sort(0, n - 1, key, label);

    return 0;
}