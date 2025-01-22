#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxApplications(vector<int>& server_capacity, vector<int>& app_requirements) {
    int N = server_capacity.size();
    int M = app_requirements.size();
    int total_capacity = 0;
    
    for (int i = 0; i < N; ++i) {
        total_capacity += server_capacity[i];
    }
    
    vector<vector<int>> dp(M + 1, vector<int>(total_capacity + 1, 0));
    
    for (int i = 1; i <= M; ++i) {
        for (int j = 0; j <= total_capacity; ++j) {
            if (j >= app_requirements[i - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - app_requirements[i - 1]] + 1);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[M][total_capacity];
}

int main() {
    int N;
    cin >> N;
    vector<int> server_capacity(N);
    for (int i = 0; i < N; ++i) {
        cin >> server_capacity[i];
    }
    
    int M;
    cin >> M;
    vector<int> app_requirements(M);
    for (int i = 0; i < M; ++i) {
        cin >> app_requirements[i];
    }
    
    int result = maxApplications(server_capacity, app_requirements);
    cout << result << endl;
    
    return 0;
}
