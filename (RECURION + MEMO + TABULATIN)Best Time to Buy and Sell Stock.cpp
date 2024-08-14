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
        int ans =  check(prices, 0 , INT_MAX , 0 , dp);
        return ans; 
    }
};
// tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> dp(n+1, 0); // DP array to store the maximum profit up to each day
        int min_price = INT_MAX; // Initialize min_price to a very high value
        int max_profit = 0; // Variable to keep track of the maximum profit found so far
        dp[0] = 0;
        for (int i = 0; i < n; i++){
            if (prices[i] < min_price) {
                min_price = prices[i]; // Update the minimum price found so far
            }
            if(i > 0){
                dp[i] = max(dp[i-1], prices[i] - min_price); // Calculate the max profit possible up to day i
            }else{
                dp[i] = 0; // No profit possible on the first day
            }
            max_profit = max(max_profit, dp[i]); // Update the overall maximum profit
        }

        return max_profit; 
    }
};
