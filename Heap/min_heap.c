#include <stdio.h>
#include <stdlib.h>

#include "min_heap.h"


struct minHeap* createHeap(int capacity){
    struct minHeap* heap = (struct minHeap*)malloc(sizeof(*heap));
    heap->array = (int*)malloc(capacity * sizeof(int));
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

extern int freeHeap(struct minHeap* heap){
    free(heap->array);
    free(heap);
}

static void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct minHeap* heap, int index){
    int smallest = index;
    int leftChild = (2 * index) + 1;
    int rightChild = (2 * index) + 2;

    if(leftChild < heap->size && heap->array[leftChild] < heap->array[smallest]){
        smallest = leftChild;
    }

    if(rightChild < heap->size && heap->array[rightChild] < heap->array[smallest]){
        smallest = rightChild;
    }

    if(smallest != index){
        swap(&heap->array[index], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

void insert(struct minHeap* heap, int value){
    if(heap->size == heap->capacity){
        puts("Heap is full");
        return;
    }
    int index = heap->size;
    heap->array[index] = value;
    heap->size++;
    
    while(index != 0 && heap->array[index] < heap->array[(index - 1) / 2]){
        swap(&heap->array[index], &heap->array[(index -1) / 2]);
        index = (index - 1) / 2;
    }
}

int extractMin(struct minHeap* heap){
    if(heap->size == 0){
        puts("Heap is empty");
        return -1;
    }

    int min = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return min;
}

void printHeap(struct minHeap* heap){
    printf("Heap elements: ");
    for(int i = 0; i < heap->size; i++){
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}