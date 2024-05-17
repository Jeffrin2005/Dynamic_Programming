class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0); // dp[i] represents the max sum up to index i-1
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int maxi = INT_MIN;
            // Try all possible lengths of subarrays ending at index i-1
            for (int j = i - 1; j >= max(0, i - k); --j) {
                maxi = max(maxi, arr[j]); // Update the maximum in the current subarray
                int tsum = maxi * (i - j); // Total sum if we partition here
                dp[i] = max(dp[i], dp[j] + tsum); // Update sum considering the partition
            }
        }
        return dp[n]; // The answer for the whole array up to index n-1
    }
};
