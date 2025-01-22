#include <iostream>
using namespace std;

void binary_search(int[], int, int, int);
void bubble_sort(int[], int);

int main() {
    int key, size;
    int list[25];

    // Input the size of the list
    cin >> size;

    // Input the elements of the list
    for (int i = 0; i < size; i++) {
        cin >> list[i];
    }

    // Sort the list using bubble sort
    bubble_sort(list, size);

    // Input the key to search
    cin >> key;

    // Perform binary search
    binary_search(list, 0, size - 1, key);

    return 0;
}

void bubble_sort(int list[], int size) {
    int temp;

    // Bubble sort algorithm
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (list[i] > list[j]) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

void binary_search(int list[], int lo, int hi, int key) {
    if (lo > hi) {
        cout << "Key not found" << endl;
        return;
    }

    int mid = (lo + hi) / 2;

    if (list[mid] == key) {
        cout << "Key found" << endl;
    } else if (list[mid] > key) {
        binary_search(list, lo, mid - 1, key);
    } else {
        binary_search(list, mid + 1, hi, key);
    }
}
