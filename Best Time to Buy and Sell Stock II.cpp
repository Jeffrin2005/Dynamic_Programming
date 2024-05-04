
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0)); 
        vector<int>v(n + 1);
        for(int i = 0; i < n; i++){
            v[i + 1] = prices[i];
        }
        dp[n][0] = 0;
        dp[n][1] = 0;
        1
        for (int ind = n; ind >= 1; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy){// 1 means buy and 0 means sell 
                    // Considering buying on this day
                    dp[ind][buy] = max(-v[ind] + dp[ind+1][0], dp[ind+1][1]);
                } else {
                    // Considering selling on this day
                    dp[ind][buy] = max(v[ind] + dp[ind+1][1], dp[ind+1][0]);
                }
            }
        }
        return dp[1][1]; // Return the result from the first day with the option to buy
    }
};
