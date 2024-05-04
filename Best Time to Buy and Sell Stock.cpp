#include <bits/stdc++.h>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> dp(n + 1, 0);
        vector<int> v(n + 1);
        for (int i = 0; i < n; i++) {
            v[i + 1] = prices[i]; // convertin 0 base indexin to 1 base indexing 
        }
        int minPrice = INT_MAX;
        dp[0] =0;
        for (int i = 1; i <= n; i++){
            // Update the minimum price found so far
            minPrice = min(minPrice, v[i]);
            // Calculate the profit if selling on the current day
            int profit = v[i] - minPrice;
            // Compare the profit with the maximum profit of the previous day
            dp[i] = max(dp[i - 1], profit);
        }
        // The maximum profit is the last element in the dp array
        return dp[n];
    }
};
