#include <iostream>
#include <vector>
using namespace std;

// Utility function to get max of two integers
int max(int x, int y) { return (x > y) ? x : y; }

// Returns the length of the longest palindromic subsequence
int lps(string& seq, int i, int j, vector<vector<int>>& dp) {
    // Base Case 1: If there is only 1 character
    if (i == j) {
        return dp[i][j] = 1;
    }

    // Base Case 2: If there are only 2 characters and both are same
    if (seq[i] == seq[j] && i + 1 == j) {
        return dp[i][j] = 2;
    }

    // If the value is already computed, return it
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    // If the first and last characters match
    if (seq[i] == seq[j]) {
        return dp[i][j] = lps(seq, i + 1, j - 1, dp) + 2;
    }

    // If the first and last characters do not match
    return dp[i][j] = max(lps(seq, i, j - 1, dp), lps(seq, i + 1, j, dp));
}

// Driver Code
int main() {
    string seq;
    cin >> seq;
    int n = seq.length();
    
    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << lps(seq, 0, n - 1, dp) << endl;

    return 0;
}
