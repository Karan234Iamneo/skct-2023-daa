//Write a program to compute the sum of elements in an array using recursion.
#include <iostream>
using namespace std;

// Recursive function to calculate the sum of array elements
int calsum(int arr[], int n) {
    if (n <= 0)
        return 0;
    return calsum(arr, n - 1) + arr[n - 1];
}

int main() {
    int n;

    // Input array size
    cin >> n;

    // Declare array
    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Calculate sum of array elements
    int sum = calsum(arr, n);

    // Output the result
    cout << "The sum of the elements in the array is " << sum << endl;

    return 0;
}
