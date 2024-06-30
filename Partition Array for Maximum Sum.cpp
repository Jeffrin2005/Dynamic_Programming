class Solution {
private:
    int solve(vector<int>& arr, int k, int i, vector<int>& dp) {
        int n = arr.size();
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        int maxi = 0;
        int ans = 0 ; 
        for (int j = i; j < min(i + k, n); j++) {
            maxi = max(maxi, arr[j]);
            ans = max(ans, (j - i + 1) * maxi + solve(arr, k, j + 1, dp));
        }
        dp[i] = ans;
        return dp[i];
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, k, 0, dp);
    }
};
