#include <iostream>
using namespace std;

int main() {
    int arr[10], n, key;

    // Input the size of the array
    cin >> n;

    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Insertion sort algorithm
    for (int i = 1; i < n; i++) {
        key = arr[i];
        int j = i - 1;

        // Shift elements that are greater than `key` to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
