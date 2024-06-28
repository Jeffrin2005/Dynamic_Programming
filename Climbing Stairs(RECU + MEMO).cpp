class Solution {
private:
    int check(vector<int>&dp, int i ){
        if(i <= 1) return 1;
        if(dp[i] != -1) return dp[i];
        dp[i] = check(dp , i - 1) + check(dp , i - 2);
        return dp[i]; 
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n + 1, -1);
        return check(dp, n);
        
    }
};
