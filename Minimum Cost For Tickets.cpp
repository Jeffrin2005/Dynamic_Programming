class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0); 
        for (int i = n - 1; i >= 0; i--) {
            int pass1 = upper_bound(days.begin(), days.end(), days[i] + 1 - 1) - days.begin();
            int pass7 = upper_bound(days.begin(), days.end(), days[i] + 7 - 1) - days.begin();
            int pass30 = upper_bound(days.begin(), days.end(), days[i] + 30 - 1) - days.begin();
            int c1, c7, c30; 
                c1 = dp[pass1] + costs[0]; 
                c7 = dp[pass7] + costs[1];
                c30 = dp[pass30] + costs[2];
            dp[i] = min({c1, c7, c30});
        }
        return dp[0];
    }
};
