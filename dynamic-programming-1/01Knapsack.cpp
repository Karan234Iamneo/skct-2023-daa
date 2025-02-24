#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack using Dynamic Programming
int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> K(n + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    int n, W;
    cin >> n;
    
    vector<int> wt(n), val(n);
    
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cin >> W;
    
    cout << knapSack(W, wt, val, n) << endl;

    return 0;
}
