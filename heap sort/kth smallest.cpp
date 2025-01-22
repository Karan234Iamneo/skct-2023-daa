#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int findKthSmallest(vector<int>& A, int k) {
    // Max-heap to store the k smallest elements
    priority_queue<int> pq;

    // Add the first k elements to the max-heap
    for (int i = 0; i < k; i++) {
        pq.push(A[i]);
    }

    // Process the remaining elements
    for (int i = k; i < A.size(); i++) {
        if (A[i] < pq.top()) {
            pq.pop();
            pq.push(A[i]);
        }
    }

    // The top element is the k-th smallest
    return pq.top();
}

int main() {
    int n, k;

    // Input array size
    cin >> n;

    // Input array elements
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Input value of k
    cin >> k;

    // Find and print the k-th smallest element
    cout << findKthSmallest(a, k) << endl;

    return 0;
}
