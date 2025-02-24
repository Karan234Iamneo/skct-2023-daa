#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumNonAdjacentGrid(vector<vector<int>>& grid) {
    int N = grid.size();
    int M = grid[0].size();
    if (N == 0 || M == 0) return 0;

    // Create a DP table to store maximum sums
    vector<vector<int>> dp(N, vector<int>(M, 0));

    // Initialize the first row of the DP table
    for (int j = 0; j < M; j++) {
        dp[0][j] = grid[0][j];
    }

    // Fill the DP table row by row
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int maxPrev = 0;
            // Check cells from the previous row that are not adjacent
            for (int k = 0; k < M; k++) {
                if (k != j - 1 && k != j && k != j + 1) {
                    maxPrev = max(maxPrev, dp[i - 1][k]);
                }
            }
            dp[i][j] = grid[i][j] + maxPrev;
        }
    }

    // Find the maximum value in the last row
    int maxSum = 0;
    for (int j = 0; j < M; j++) {
        maxSum = max(maxSum, dp[N - 1][j]);
    }

    return maxSum;
}

int main() {
    int N,M;
    cin>>N>>M;
    
    vector<vector<int>> grid(N,vector<int>(M));
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            int val;
            cin>>val;
            grid[i][j] = val;
        }
    }

    cout << maxSumNonAdjacentGrid(grid) << endl;
    return 0;
}
