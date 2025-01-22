#include <iostream>

// Function to maintain the min heap property
void minHeapify(int heap[], int size, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        std::swap(heap[i], heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

// Function to insert an element into the min heap
void insertIntoMinHeap(int heap[], int& size, int value) {
    // Add the new element at the end of the heap
    size++;
    int currentIndex = size - 1;
    heap[currentIndex] = value;

    // Maintain the min heap property by comparing with parent nodes
    while (currentIndex > 0 && heap[currentIndex] < heap[(currentIndex - 1) / 2]) {
        std::swap(heap[currentIndex], heap[(currentIndex - 1) / 2]);
        currentIndex = (currentIndex - 1) / 2;
    }
}

int main() {
    int maxHeapSize;
    // std::cout << "Enter the maximum heap size: ";
    std::cin >> maxHeapSize;

    int minHeap[maxHeapSize]; // Create a min heap with the specified maximum size
    int heapSize = 0;

    // std::cout << "Enter elements to insert into the min heap (-1 to stop):\n";

    int element;
    while (heapSize < maxHeapSize) {
        std::cin >> element;

        if (element == -1) {
            break;
        }

        insertIntoMinHeap(minHeap, heapSize, element);
    }

    std::cout << "Min Heap: ";
    for (int i = 0; i < heapSize; i++) {
        std::cout << minHeap[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
