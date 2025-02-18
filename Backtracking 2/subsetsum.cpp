#include <iostream>
using namespace std;

int subset_count = 0;  // Global variable to count valid subsets

// Backtracking function to find subsets that sum up to the target
void subset_sum(int list[], int n, int sum, int start, int target_sum) {
    if (sum == target_sum) { 
        subset_count++;  // Found a valid subset
        
        // Continue searching for other subsets
        if (start < n) 
            subset_sum(list, n, sum - list[start - 1], start, target_sum);
    } 
    else {
        for (int i = start; i < n; i++) {
            subset_sum(list, n, sum + list[i], i + 1, target_sum);
        }
    }
}

int main() {
    int n, target_sum;
    
    // Read input
    cin >> n;
    int list[n];
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    cin >> target_sum;
    
    // Call the subset sum function
    subset_sum(list, n, 0, 0, target_sum);
    
    // Print the total count of subsets
    cout << subset_count << endl;
    
    return 0;
}
