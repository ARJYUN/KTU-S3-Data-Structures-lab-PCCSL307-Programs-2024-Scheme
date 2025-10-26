#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct HeapNode {
    int value;   
    int arrIdx;  
    int elemIdx; 
};

void minHeapify(struct HeapNode heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].value < heap[smallest].value)
        smallest = left;

    if (right < size && heap[right].value < heap[smallest].value)
        smallest = right;

    if (smallest != i) {
        struct HeapNode temp=heap[i];
        heap[i]=heap[smallest];
        heap[smallest]=temp;
        minHeapify(heap, size, smallest);
    }
}

void buildMinHeap(struct HeapNode heap[], int size) {
    int i;
    for (i = (size - 1) / 2; i >= 0; i--)
        minHeapify(heap, size, i);
}

int *mergeKSortedArrays(int arr[][100], int K, int N) {
    int *output = (int *)malloc(K * N * sizeof(int));
    struct HeapNode *heap = (struct HeapNode *)malloc(K * sizeof(struct HeapNode));

    for (int i = 0; i < K; i++) {
        heap[i].value = arr[i][0];
        heap[i].arrIdx = i;
        heap[i].elemIdx = 0;
    }

    buildMinHeap(heap, K);

    
    for (int i = 0; i < K * N; i++) {
        struct HeapNode root = heap[0];
        output[i] = root.value;

        if (root.elemIdx + 1 < N)
            heap[0].value = arr[root.arrIdx][root.elemIdx + 1],
            heap[0].elemIdx++;
        else
            heap[0].value = INT_MAX; 

        minHeapify(heap, K, 0);
    }

    free(heap);
    return output;
}

int main() {
    int K, N;

    printf("Enter number of sorted arrays (K): ");
    scanf("%d", &K);
    printf("Enter number of elements in each array (N): ");
    scanf("%d", &N);

    int arr[100][100];
    printf("Enter the sorted arrays:\n");
    for (int i = 0; i < K; i++) {
        printf("Array %d: ", i + 1);
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);
    }

    int *mergedArray = mergeKSortedArrays(arr, K, N);

    printf("\nMerged Sorted Array:\n");
    for (int i = 0; i < K * N; i++)
        printf("%d ", mergedArray[i]);
    printf("\n");

    free(mergedArray);
    return 0;
}

