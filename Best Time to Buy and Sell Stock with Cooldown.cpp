class Solution {
private:
    int dp(int i, int buy, vector<int>& prices, vector<vector<int>>& memo) {
        if (i >= prices.size()) return 0;
        if (memo[i][buy] != -1) return memo[i][buy];
        if (buy) {
            // Choice to buy or not buy
            memo[i][buy] = max(-prices[i] + dp(i + 1, 0, prices, memo), dp(i + 1, 1, prices, memo));
        } else {
            // Choice to sell or not sell
            memo[i][buy] = max(prices[i] + dp(i + 2, 1, prices, memo), dp(i + 1, 0, prices, memo));
        }
        
        return memo[i][buy];
    }
    public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));
        return dp(0, 1, prices, memo);
    }
};// TABULATION
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n + 2, vector<int>(2));
        
        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy) {
                    dp[i][buy] = max(-p[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                }
                else dp[i][buy] = max(p[i] + dp[i + 2][1], 0 + dp[i + 1][0]);
            }
        }
        return dp[0][1];
    }
};
