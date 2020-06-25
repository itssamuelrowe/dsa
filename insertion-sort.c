#include <stdio.h>

int main() {
    int array[] = { 5, 3, 5, 19, 11, 8, 12, 16 };
    int size = sizeof (array) / sizeof (int);

    printf("[before]\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("%d    ", array[i]);
    }
    puts("");

    for (i = 1; i < size; i++) {
        int j = i - 1;
        int v = array[i];
        while (j >= 0) {
            if (v < array[j]) {
                array[j + 1] = array[j];
                array[j] = v;
                j--;
            }
            else {
                break;
            }
        }
    }

    printf("[after]\n");
    for (i = 0; i < size; i++) {
        printf("%d    ", array[i]);
    }
    puts("");

    return 0;
}