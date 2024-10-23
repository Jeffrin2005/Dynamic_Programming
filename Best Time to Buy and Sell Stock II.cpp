// RECURSION + MEMO
class Solution {
public:
    int solve(int i, int n, vector<int> &prices, int buy, vector<vector<int>> &dp){
        if(i == n) return 0; 
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit;
        if(buy == 1){ // If we can buy the stock
            // Option 1: Buy the stock and move to the next day without holding
            int buy_stock = -prices[i] + solve(i + 1, n, prices, 0, dp);
            // Option 2: Do not buy the stock and move to the next day
            int skip_buy = solve(i + 1, n, prices, 1, dp);
            profit = max(buy_stock, skip_buy);
        } else{ // If we are holding a stock and can choose to sell
            // Option 1: Sell the stock and move to the next day without holding
            int sell_stock = prices[i] + solve(i + 1, n, prices, 1, dp);
            // Option 2: Do not sell the stock and continue holding
            int skip_sell = solve(i + 1, n, prices, 0, dp);
            profit = max(sell_stock, skip_sell);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int buy = 1; // 1 means we can buy, 0 means we cannot buy
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, n, prices, buy, dp);
    }
};///    TABULATION 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[i][0] - max profit on day i when not holding a stock
        // dp[i][1] - max profit on day i when holding a stock
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // On day n, profit is 0 whether holding or not holding
        dp[n][0] = 0;
        dp[n][1] = 0;
        // Iterate from day n-1 downto day 0
        for(int i = n - 1; i >= 0; i--){
            for(int buy = 0; buy <= 1;buy++){
                if(buy == 1){
                    // Option 1: Buy the stock
                    int buy_stock = -prices[i] + dp[i + 1][0];
                    // Option 2: Do not buy the stock
                    int skip_buy = dp[i + 1][1];
                    dp[i][buy] = max(buy_stock, skip_buy);
                }else{
                    // Option 1: Sell the stock
                    int sell_stock = prices[i] + dp[i + 1][1];
                    // Option 2: Do not sell the stock
                    int skip_sell = dp[i + 1][0];
                    dp[i][buy] = max(sell_stock, skip_sell);
                }
            }
        }
        // The maximum profit starts at day 0 with the ability to buy
        return dp[0][1];
    }
};
