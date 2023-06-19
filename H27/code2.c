#include <stdio.h>
#define capacity 15 /* ナップサックの容量 */
#define item 4      /* 品物の数 */
int main(void) {
    int size[] = {0, 2, 6, 6, 2};
    int value[] = {0, 20, 30, 15, 25};
    int sack[item + 1][capacity + 1];
    int i, j, max, index;

    for (i = 0; i <= item; i++)
        for (j = 0; j <= capacity; j++)
            sack[i][j] = -1; /*ナップサックの初期化*/
    sack[0][0] = 0;
    /*品物が入っていない(大きさの和が0)のナップサックの総価値は0*/

    for (i = 1; i <= item; i++)
        for (j = 0; j <= capacity; j++)
            if (sack[i - 1][j] != -1) {
                if (sack[i - 1][j] > sack[i][j]) sack[i][j] = sack[i - 1][j];
                if (j + size[i] <= capacity)
                    sack[i][j + size[i]] = sack[i - 1][j] + value[i];
            }

    max = 0;
    index = 0;
    for (j = 0; j <= capacity; j++)
        if (sack[item][j] > max) {
            max = sack[item][j];
            index = j;
        }
    for (i = item; i >= 1; i--)
        if (index >= size[i] &&
            sack[i][index] == sack[i - 1][index - size[i]] + value[i]) {
            printf("item %d is in a knapsack\n", i);
            index = index - size[i];
        }
    return 0;
}