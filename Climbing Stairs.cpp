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
// TABULATION
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1; 
        for (int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n]; 
    }
};
