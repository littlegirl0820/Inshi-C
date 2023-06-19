#include <stdio.h>
#define MAXN 100

void functionA(int a[], int b[], int t, int w) {
    int tmp, i, j;
    for (i = t + 1; i <= w; i++) {
        for (j = t; j <= w - i; j++) {
            if (a[j] > a[j + 1]) {
                tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
                tmp = b[j + 1];
                b[j + 1] = b[j];
                b[j] = tmp;
            }
        }
    }
}

int functionB(int a[], int x, int n) {
    int t, w, m;
    t = 0;
    w = n - 1;
    do {
        m = (t + w) / 2;
        if (x < a[m])
            w = m - 1;
        else
            t = m + 1;
    } while (t <= w);
    if (w >= 0 && x == a[w])
        return w;
    else
        return -1;
}

int main() {
    int n, i, k;
    FILE *fp;
    int win[MAXN], grade[MAXN], lot;
    fp = fopen("win.txt", "r");
    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++) fscanf(fp, "%d %d", &win[i], &grade[i]);
    fclose(fp);
    functionA(win, grade, 0, n - 1);

    fp = fopen("lots.txt", "r");
    while (fscanf(fp, "%d", &lot) != EOF) {
        if ((k = functionB(win, lot, n)) != -1) {
            printf("***winning number: %4d, grade: %d\n", lot, grade[k]);
        }
    }
    fclose(fp);
    return 0;
}
