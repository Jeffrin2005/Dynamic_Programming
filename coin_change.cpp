
class Solution {
public:
    long long int solve(vector<int>& coins, int n, int amount, vector<vector<int>>& dp) {
        // Base Case 1: If the remaining amount is 0
        if (amount == 0) return 0;
        // Base Case 2: If no coins are left but amount is still positive
        if (n == 0) return INT_MAX;
        // If the result for this state is already computed, return it
        if (dp[n][amount] != -1) return dp[n][amount];
        long long int ans;
        // Decision: Include or Exclude the current coin
        if (coins[n - 1] > amount){ // Exclude the current coin
            ans = solve(coins, n - 1, amount, dp);
        }
        else { // Choose to exclude or include the current coin
            long long int exclude = solve(coins, n - 1, amount, dp);
            long long int include = 1 + solve(coins, n, amount - coins[n - 1], dp);
            ans = min(exclude, include);
        }
        return dp[n][amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
     vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int ans = solve(coins, n, amount, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};// TABULATION 


class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        int n = coins.size();
        // Initialize a DP table where dp[i][j] represents the minimum number of coins
        // needed to make up amount j using the first i coins.
     vector<vector<int>> dp(n + 1,vector<int>(amount + 1, INT_MAX - 1));
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        // Base Case 2: If no coins are available, it's impossible to make any amount > 0.
        for(int j = 1; j <= amount; ++j){
            dp[0][j] = INT_MAX - 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount;j++){
                if(coins[i - 1] > j){
                    // Current coin is larger than the amount j, exclude it.
                    dp[i][j] = dp[i - 1][j];
                }else{
                    // Choose the minimum between excluding the current coin and including it.
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                }
            }
        }
        // If dp[n][amount] is still INT_MAX - 1, it means it's not possible to form the amount.
        return (dp[n][amount] == INT_MAX - 1) ? -1 : dp[n][amount];
    }
};
