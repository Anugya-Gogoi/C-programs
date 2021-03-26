#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap MinHeap;
struct MinHeap {
    int* arr;
    int size;
    int capacity;
};

int parent(int i)
{
    return (i - 1) / 2;
}

int left_child(int i) {
    return (2*i + 1);
}

int right_child(int i) {
    return (2*i + 2);
}

int min_element(MinHeap* heap)
{
    return heap->arr[0];
}

MinHeap* init_minheap(int capacity) {
    MinHeap* minheap = (MinHeap*) calloc (1, sizeof(MinHeap));
    minheap->arr = (int*) calloc (capacity, sizeof(int));
    minheap->capacity = capacity;
    minheap->size = 0;
    return minheap;
}

MinHeap* insert_minheap(MinHeap* heap, int element) {
    if (heap->size == heap->capacity) {
        printf("\nCannot insert %d. Heap is already full!\n");
        return heap;
    }

    heap->size++;
    heap->arr[heap->size - 1] = element;

    int curr = heap->size - 1;
    while (curr > 0 && heap->arr[parent(curr)] > heap->arr[curr]) {
        int temp = heap->arr[parent(curr)];
        heap->arr[parent(curr)] = heap->arr[curr];
        heap->arr[curr] = temp;

        curr = parent(curr);
    }
    return heap;
}

MinHeap* heapify(MinHeap* heap, int index) {

    if (heap->size <= 1)
        return heap;

    int left = left_child(index);
    int right = right_child(index);
    int smallest = index;

    if (left < heap->size && heap->arr[left] < heap->arr[index])
        smallest = left;

    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;
    if (smallest != index)
    {
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[smallest];
        heap->arr[smallest] = temp;
        heap = heapify(heap, smallest);
    }

    return heap;
}

MinHeap* delete_minimum(MinHeap* heap) {
    if (!heap || heap->size == 0)
        return heap;

    int size = heap->size;
    int last_element = heap->arr[size-1];
    heap->arr[0] = last_element;
    heap->size--;
    size--;
    heap = heapify(heap, 0);
    return heap;
}

MinHeap* delete_element(MinHeap* heap, int index) {

    heap->arr[index] = min_element(heap) - 1;
    int curr = index;
    while (curr > 0 && heap->arr[parent(curr)] > heap->arr[curr]) {
        int temp = heap->arr[parent(curr)];
        heap->arr[parent(curr)] = heap->arr[curr];
        heap->arr[curr] = temp;
        curr = parent(curr);
    }

    heap = delete_minimum(heap);
    return heap;
}

void print_heap(MinHeap* heap)
{
    printf("\nMin Heap tree:\n");
    for (int i=0; i<heap->size; i++) {
        printf("%d\t", heap->arr[i]);
    }
}

void free_minheap(MinHeap* heap) {
    if (!heap)
    return;
    free(heap->arr);
    free(heap);
}

int main() {
    MinHeap* heap = init_minheap(10);
    insert_minheap(heap, 4);
    insert_minheap(heap, 74);
    insert_minheap(heap, 8);
    insert_minheap(heap, 24);
    insert_minheap(heap, 50);
    insert_minheap(heap, 5);
    insert_minheap(heap, 9);
    print_heap(heap);

    delete_element(heap, 3);

  //  print_heap(heap);
    free_minheap(heap);
    return 0;
}
