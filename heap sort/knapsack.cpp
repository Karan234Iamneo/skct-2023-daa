#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int capacity, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    return dp[n][capacity];
}

int main() {
    int n, capacity;
    cin >> n >> capacity;
    
    vector<int> weights(n);
    vector<int> values(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
    }
    
    cout << knapsack(capacity, weights, values, n) << endl;
    
    return 0;
}
