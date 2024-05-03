class Solution {
public:
    int minInsertions(string s) {
              string t = s;
        reverse(t.begin(), t.end());
           int n= s.size();
        int m = t.size();
          vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
         s = "#" + s;
            t = "#" + t;
        dp[0][0] = 0;
        for(int i=1; i<=n; i++) dp[i][0] = 0;
        for(int i=1; i<=m; i++) dp[0][i] = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if(s[i] == t[j]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else  dp[i][j] = max(0 +  dp[i][j - 1], 0 + dp[i - 1][j]);
            }
        }
           return n - dp[n][m];
    }
};
