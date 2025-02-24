#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    // Create a DP array to store the maximum sum of increasing subsequences ending at each index
    vector<int> dp(nums.begin(), nums.end());

    // Fill the DP array
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
        }
    }

    // Find the maximum value in dp array
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cin>>n;
    
    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        int elem;
        cin>>elem;
        nums[i] = elem;
    }

    int result = maxSumIncreasingSubsequence(nums);
    cout<< result << endl; // Expected output: 106

    return 0;
}
