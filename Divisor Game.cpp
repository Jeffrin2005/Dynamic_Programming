class Solution {
public:
    bool divisorGameUtil(int n, vector<int>& dp)
    {
        if(dp[n] != -1)
            return dp[n];
        if(n == 1)
        {
            dp[n] = false;
            return dp[n];
        }
        for(auto x = 1; x < n; ++x)
            if(n%x == 0 && !divisorGameUtil(n-x, dp))
            {
                dp[n] = true;
                return dp[n];
            }
        dp[n] = false;
        return dp[n];       
    }
    bool divisorGame(int n) {
        vector<int> dp(n+1,-1);
        return divisorGameUtil(n, dp);
    }
};
