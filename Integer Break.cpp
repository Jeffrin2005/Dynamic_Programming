class Solution {
public:
    int integerBreak(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n, 0)); 
        for (int i = 1; i <= n; i++) dp[i][0] = 1;
        for (int i = 1; i < n; i++) dp[0][i] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j < n; j++){
                    dp[i][j] = dp[i][j - 1];// not pick 
                    if(i >= j){
                    dp[i][j] = max(dp[i][j - 1], j * dp[i - j][j]);
                    }
                }
            }
        
        return dp[n][n - 1]; 
    }
};
