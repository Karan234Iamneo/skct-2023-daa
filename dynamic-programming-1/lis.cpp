#include <iostream>
#include <vector>
using namespace std;

// Function to find the length of the longest increasing subsequence
int lis(vector<int>& arr, int n) {
    vector<int> lis(n, 1); // Initialize LIS array with 1
    int max_lis = 1;

    // Compute LIS values in bottom-up manner
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
        max_lis = max(max_lis, lis[i]); // Keep track of max LIS value
    }

    return max_lis;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << lis(arr, n) << endl;

    return 0;
}
