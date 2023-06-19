#include <stdio.h>

#define MAX 8

struct item_t {
    int key;
    char val;
};

void sort(struct item_t data[]) {
    int i, j, tmp_key;
    char tmp_val;

    for (i = 1; i < MAX; i++)
        for (j = i; j > 0 && data[j - 1].key >= data[j].key; j--) {
            tmp_key = data[j].key;
            tmp_val = data[j].val;
            data[j].key = data[j - 1].key;
            data[j].val = data[j - 1].val;
            data[j - 1].key = tmp_key;
            data[j - 1].val = tmp_val;
        }
}

void show(struct item_t data[]) {
    int i = MAX;
    while (i--) printf("(%d,%c) ", data[i].key, data[i].val);
    printf("\n");
}

int main(void) {
    struct item_t data[MAX] = {{5, 'a'}, {2, 'd'}, {6, 'e'}, {4, 'h'},
                               {1, 'b'}, {8, 'f'}, {3, 'c'}, {7, 'g'}};
    // struct item_t data[MAX] = {{1, 'a'}, {2, 'd'}, {4, 'e'}, {6, 'h'},
    //                            {8, 'b'}, {3, 'f'}, {5, 'c'}, {7, 'g'}};
    // struct item_t data[MAX] = {{8, 'c'}, {1, 'f'}, {2, 'h'}, {3, 'g'},
    //                            {4, 'd'}, {5, 'e'}, {6, 'b'}, {7, 'c'}};
    // struct item_t data[MAX] = {{8, 'c'}, {1, 'f'}, {2, 'h'}, {3, 'g'},
    //                            {4, 'd'}, {5, 'e'}, {6, 'b'}, {7, 'c'}};
    // struct item_t data[MAX] = {{2, 'x'}, {4, 'y'}, {6, 'z'}, {8, 'w'},
    //                            {2, 's'}, {4, 't'}, {6, 'u'}, {8, 'v'}};

    sort(data);

    show(data);

    return 0;
}