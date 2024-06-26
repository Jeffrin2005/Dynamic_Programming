class Solution {
private:
    int check(vector<int>& prices, int i, vector<int>& dp){
        int n1 = prices.size();
        if (i >= n1) return 0;
        if (dp[i] != -1) return dp[i];
        int min_price = prices[i];
        int max_profit = 0;
        for (int sellday = i + 1; sellday < n1; sellday++) {
            max_profit = std::max(max_profit, prices[sellday] - min_price);
        }
        dp[i] = max_profit;
        return dp[i]; 
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1, -1);
        int ans = 0; 
        for (int i = 0; i < n; i++) {
            ans = std::max(ans, check(prices, i, dp));
        }
        return ans;  
    }
};
