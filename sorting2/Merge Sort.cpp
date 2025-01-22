#include <iostream>

using namespace std;

// Merge two sorted arrays into a single sorted array
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int mergedArray[]) {
    int i = 0, j = 0, k = 0;

    // Compare elements from both arrays and merge them into the result
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            mergedArray[k] = arr1[i];
            i++;
        } else {
            mergedArray[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from arr1 (if any)
    while (i < size1) {
        mergedArray[k] = arr1[i];
        i++;
        k++;
    }

    // Copy any remaining elements from arr2 (if any)
    while (j < size2) {
        mergedArray[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int size1, size2;

    // cout << "Enter the size of the first sorted array: ";
    cin >> size1;

    int arr1[size1];

    // cout << "Enter the elements of the first sorted array:" << endl;
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    // cout << "Enter the size of the second sorted array: ";
    cin >> size2;

    int arr2[size2];

    // cout << "Enter the elements of the second sorted array:" << endl;
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    int mergedSize = size1 + size2;
    int mergedArray[mergedSize];

    mergeSortedArrays(arr1, size1, arr2, size2, mergedArray);

    // cout << "Merged Array: ";
    for (int i = 0; i < mergedSize; i++)
        cout << mergedArray[i] << " ";
    // cout << endl;

    return 0;
}
