class Solution {
public:
        int lcs(string s1, string s2) {
        int n= s1.size();
        int m = s2.size();
          vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
           s1 = "#" + s1;
        s2 = "#" + s2;
        dp[0][0] = 0;
        for(int i=1; i<=n; i++) dp[i][0] = 0;
        for(int i=1; i<=m; i++) dp[0][i] = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if(s1[i] == s2[j]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else  dp[i][j] = max(0 +  dp[i][j - 1], 0 + dp[i - 1][j]);
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);  
    }
}; Longest Palindromic Subsequence
