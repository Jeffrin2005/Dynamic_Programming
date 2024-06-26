class Solution {
private:
    int check(vector<int>&prices, int i ,int min_price, int max_profit, vector<int>&dp){
        int n1 = prices.size();
        if(i >= n1) return max_profit;
        if(dp[i] != -1) return dp[i];
        if(prices[i] < min_price){
            min_price = prices[i];
        }
        int profit = prices[i] - min_price;
        if(profit > max_profit){
            max_profit = profit;
        }
        dp[i]  = check(prices, i + 1, min_price, max_profit, dp);
        return dp[i];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>dp(n + 1, -1);
        return check(prices, 0 , INT_MAX , 0 , dp);
    }
};
