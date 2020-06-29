#include <stdio.h>

void printArray(int* array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d    ", array[i]);
    }
    puts("");
}

void swap(int* array, int x, int y) {
    int t = array[x];
    array[x] = array[y];
    array[y] = t;
}

int partition(int* array, int left, int right) {
    /* The last element is always chosen as the pivot. */
    int pivot = array[right];
    /* The partitioning technique makes use of two regions:
     * 1. The region where all the elements are smaller than the pivot.
     *    The last element in this region is indicated by `i`. Initially,
     *    this region does not exist, which is why i is assigned `left - 1`,
     *    an index outside the boundaries of the input array.
     *    The second region begins at `i + 1`.
     * 2. The region where all the elements are greater than the pivot.
     *    The last element in this region is indicated by `j`. Initially,
     *    we assume that the first element belongs to this region.
     */
    int i = left - 1;
    int j;
    /* Rearrange the elements while finding the smaller and the larger
     * regions. Exclude the pivot element from this step.
     */
    for (j = left; j < right; j++) {
    	/* If the current element is smaller than the pivot, it belongs to
    	 * the smaller region. Since we know that the larger region starts
    	 * at `i + 1`, we swap the current element with it and grow the smaller
    	 * region by 1.
    	 */
        if (array[j] <= pivot) {
            i++;
            swap(array, i, j);
        }
    }
    /* The starting of the larger region is the right place for the pivot,
     * because on its left lies the smaller region and on its right lies the
     * larger region. Therefore, swap the first element of the larger region
     * with the pivot. The index of the pivot becomes the partition index.
     */
    swap(array, i + 1, right);
    return i + 1;
}

void quickSort(int* array, int left, int right) {
    /* The region to sort is empty when left index is greater or equal to
     * the right index.
     */
    if (left < right) {
    	/* Find the index at which we partition the array into subarrays. */
        int q = partition(array, left, right);
        /* Sort the subarrays recursively. */
        quickSort(array, left, q - 1);
        quickSort(array, q + 1, right);
    }
}

int main() {
    int array[] = { 2, 8, 7, 1, 3, 5, 6, 4 };
    int size = sizeof (array) / sizeof (int);

    printf("[before]\n");
    printArray(array, size);

    quickSort(array, 0, size - 1);

    printf("[after]\n");
    printArray(array, size);

    return 0;
}