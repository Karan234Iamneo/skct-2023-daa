#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute Levenshtein distance using Dynamic Programming
int compute_Levenshtein_distanceDP(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    
    // 2D matrix to store the edit distances
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;  // If str1 is empty, insert all characters of str2
            } else if (j == 0) {
                dp[i][j] = i;  // If str2 is empty, remove all characters of str1
            } else {
                // Choose the minimum operation: replace, delete, or insert
                dp[i][j] = min({
                    dp[i - 1][j - 1] + (str1[i - 1] != str2[j - 1]), // Replace
                    dp[i - 1][j] + 1,  // Delete
                    dp[i][j - 1] + 1   // Insert
                });
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << compute_Levenshtein_distanceDP(s1, s2) << endl;
    return 0;
}
