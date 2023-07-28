#ifndef MIN_HEAP_H
#define MIN_HEAP_H



struct minHeap {                                        /*The heap structure*/
    int* array;                                 
    int capacity;
    int size;
};


/*API*/

extern struct minHeap* createHeap(int capacity);       /*Creates a heap and returns a pointer to it*/
extern int freeHeap(struct minHeap* heap);             /*Frees the heap*/
extern void heapify(struct minHeap* heap, int index);  /*Restores the heap property*/
extern void insert(struct minHeap* heap, int value);   /*Inserts a value in the heap*/
extern int extractMin(struct minHeap* heap);           /*Extracts the minimum value from the heap and calls heapify*/
extern void printHeap(struct minHeap* heap);           /*Prints the whole heap*/

#endif