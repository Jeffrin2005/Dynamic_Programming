class Solution {
public:
    int check(int i, vector<int>& dp){
        
        if(i == 0) return 0;
        if(i == 1) return 1;
        if(i == 2) return 1;
        if(dp[i] != -1) return dp[i];
        dp[i] = check(i-1, dp) + check(i-2, dp) + check(i-3, dp);
        return dp[i];
    }
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return check(n, dp);
    }
};
