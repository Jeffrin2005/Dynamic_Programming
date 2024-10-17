int mod = 1e9 + 7;

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    if (arr[0] <= k) dp[0][arr[0]] = 1;

    dp[0][0] = arr[0] ? 1 : 2;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i-1][j]; // This is equivalent to nottake
            if ( arr[i] <= j) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-arr[i]]) % mod; // This adds the take part
            }
        }
    }

    return dp[n-1][k];
}
