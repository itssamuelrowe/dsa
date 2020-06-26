#include <stdio.h>

void printArray(int* array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d    ", array[i]);
    }
    puts("");
}

int main() {
    int array[] = { 5, 3, 19, 11, 8, 12, 16 };
    int size = sizeof (array) / sizeof (int);

    printf("[before]\n");
    printArray(array, size);

    /* The last element is always considered as sorted. Therefore, we sort the
     * range [0, n-1].
     */
    int limit = size - 1;
    int i;
    for (i = 0; i < limit; i++) {
        /* We assume that the current element is the smaallest in the unsorted
         * region.
         */
        int minIndex = i;
        /* Look for another element that is smaller than the current element
         * in the unsorted region. The search begins at the index immediately
         * after the current index. We already assume the current element is
         * the smallest. Therefore, it would be redundant to include it in
         * the search for the smallest element.
         *
         * The search extends to the last element. Here we include the last
         * element as well because the smallest element could occur at the
         * last index as well.
         */
        int j;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                /* Looks like we found an element smaller than the current
                 * minimum. Therfore, save the index of this element.
                 */
                minIndex = j;
            }
        }

        /* Swap the current element with the smallest element from the unsorted
         * region. Technically, you don't have to check if the smallest element
         * is some other element that isn't at the i-th index. The algorithm
         * would work just fine. However, you will increase the performance of
         * the algorithm, probably by a negligible amount, if you don't
         * swap the current element if it is the smallest element in the unsorted
         * region.
         */
        if (minIndex != i) {
            int t = array[i];
            array[i] = array[minIndex];
            array[minIndex] = t;
        }
    }

    printf("[after]\n");
    printArray(array, size);

    return 0;
}