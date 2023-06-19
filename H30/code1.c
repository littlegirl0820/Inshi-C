#include <stdio.h>
#define N_MAX 1000
int p[N_MAX];

int find(int x) {
    if (p[x] == x)
        return x;
    else
        return find(p[x]);
}

void same(int x, int y) {
    int n, m;
    n = find(x);
    m = find(y);
    if (n == m) /*同じ組織に所属する*/
        printf("%d & %d are in the same organization.\n", x, y);
    else
        printf("%d & %d are in diffrent organization.\n", x, y);
}
int main(void) {
    FILE *fp;
    int n, i, j, sv;
    fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++) p[i] = i;
    while (fscanf(fp, "%d %d", &i, &sv) != EOF) p[i] = sv;
    fclose(fp);
    fp = fopen("pair.txt", "r");
    while (fscanf(fp, "%d %d", &i, &j) != EOF) same(i, j);
    fclose(fp);
    return 0;
}