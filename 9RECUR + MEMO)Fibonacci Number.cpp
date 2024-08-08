class Solution {
public:
    int fib(int i,vector<int>&dp){
        if(i <= 1)   return i; // Base cases: F(0) = 0, F(1) = 1 
        if(dp[i] != -1) return dp[i];
        dp[i] = fib(i - 1, dp) + fib(i - 2, dp); 
        return dp[i];
    }

    int fib(int n) {
        vector<int>dp(31, -1); 
        int ans =  fib(n, dp);
        return ans; 
    }
};
