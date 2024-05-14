class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true; // Correcting this to true
        for (int i = 1; i <= m; i++) dp[i][0] = false; // s is not empty, t is empty
        for (int i = 1; i <= n; i++) dp[0][i] = true; // s is empty, t is not empty
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; 
                } else {
                    dp[i][j] = dp[i][j - 1]; 
                }
            }
        }
        return dp[m][n];
    }
};
