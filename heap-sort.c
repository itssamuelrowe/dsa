#include <stdio.h>

#define rightIndex0(node) ((node) * 2 + 1)
#define leftIndex0(node) ((node) * 2)
#define parentIndex0(node) ((node) / 2)

void printHeap(int* heap, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d    ", heap[i]);
    }
    printf("\n");
}

void maxHeapify(int* heap, int heapSize, int rootIndex) {
    int leftIndex = leftIndex0(rootIndex);
    int rightIndex = rightIndex0(rootIndex);

    /* According to the max-heap property, the root node should be the largest
     * in the given subtree. We check if this property holds in the following
     * if statement.
     */
    int largestIndex = rootIndex;

    /* If the node referred by the root index is a leaf, both the left and right
     * indexes are invalid, because leaves do not have children! They may either
     * point to nodes within the heap that is not their children or even worse,
     * an index out of the heap's bounds.
     */
    if ((leftIndex <= heapSize) && (heap[rootIndex - 1] < heap[leftIndex - 1])) {
        largestIndex = leftIndex;
    }
    
    /* We are trying to find the largest among root, left, and right nodes. Therefore,
     * compare the right node with the largest node we have found so far,
     * not the root node!
     */
    if ((rightIndex <= heapSize) && (heap[largestIndex - 1] < heap[rightIndex - 1])) {
        largestIndex = rightIndex;
    }

    /* If the largest index does not point to the root node,
     * then we need to fix the max-heap property. We do this by swapping the
     * root node with the largest node, and applying the max-heapify procedure
     * at the new index of our old root node. Why? Since the root node was
     * repositioned, chances are it may break the max-heap property within
     * the subtree where it is the new root.
     */
    if (largestIndex != rootIndex) {
        int temporary = heap[largestIndex - 1];
        heap[largestIndex - 1] = heap[rootIndex - 1];
        heap[rootIndex - 1] = temporary;
        maxHeapify(heap, heapSize, largestIndex);
    }
}

void buildHeap(int* heap, int heapSize) {
    /* The leaves are considered to be heaps of size 1, which basically
     * satisfy the max-heap property. Therefore, we start with the nodes
     * above the leaves.
     */
    int i;
    for (i = heapSize / 2; i >= 1; i--) {
        maxHeapify(heap, heapSize, i);
    }
}

void heapSort(int* heap, int heapSize) {
    /* In a max-heap, the root node holds the highest value. Therefore,
     * swap it with the last element. The largest element is now moved
     * to the sorted region in the heap. Therefore, decrease the heap
     * size to remove it.
     */
    int i;
    for (i = heapSize - 1; i > 0; i--) {
        /* Swap the largest element with the last element in the heap. */
        int temporary = heap[0];
        heap[0] = heap[i];
        heap[i] = temporary;
        /* Swapping may have caused the new root node to violate the max-heap
         * property. Therefore, apply max-heapify again. Remember that the root
         * node is at 1, not 0 because the heap is 1 based. (All I had to was
         * modify left(), right() and parent() formulas instead of worrying about
         * this everywhere in the code. FML.) Since i is zero based and the heap
         * size is 1 based, we can directly pass i without adding or subtracting
         * 1 to it.
         */
        maxHeapify(heap, i, 1);
    }
}

int main() {
    int heap[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    int size = sizeof (heap) / sizeof (int);

    printf("[*] Before building the max heap\n");
    printHeap(heap, size);
    
    buildHeap(heap, size);
    printf("[*] After building the max heap\n");
    printHeap(heap, size);

    heapSort(heap, size);
    printf("[*] After sorting\n");
    printHeap(heap, size);

    return 0;
}