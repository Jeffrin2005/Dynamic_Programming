
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);  // Initialize with INT_MAX as we need minimum
        dp[0] = 0;  // 0 coins needed to make up 0 amount

        // Iterate through amounts from 1 to the target amount
        for (int i = 1; i <= amount; i++) {
            // Iterate through available coin denominations
            for (int j = 0; j < n; j++) {
                // Check if the current coin can contribute to making up the amount i
                if (i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
                    // Update dp[i] with the minimum number of coins
                    // dp[i] = nottake
                    // dp[i-cois[j]] = take 
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        // Return the final result, -1 if not possible to make up the amount
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
