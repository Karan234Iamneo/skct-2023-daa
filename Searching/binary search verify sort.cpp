#include <iostream>
using namespace std;

bool isSorted(int arr[], int n) {
    if (n <= 1) {
        return true; // An empty array or an array with a single element is considered sorted.
    }

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If the mid element is greater than the next element, the array is not sorted.
        if (arr[mid] > arr[mid + 1]) {
            return false;
        }

        // If the mid element is greater than the first element, search the right half.
        if (arr[mid] > arr[left]) {
            left = mid + 1;
        }
        // Otherwise, search the left half.
        else {
            right = mid;
        }
    }

    return true;
}

int main() {
    int p;
    cin>>p;
    int arr[p];
    for(int i=0;i<p;i++)
    cin>>arr[i];
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isSorted(arr, n)) {
        cout << "The array is sorted." << endl;
    } else {
        cout << "The array is not sorted." << endl;
    }

    return 0;
}
