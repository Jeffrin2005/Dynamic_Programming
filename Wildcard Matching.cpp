class Solution {
public:
    bool isMatch(string s, string p) {
          int n = s.size();
          int  m = p.size();
       s = '#' + s;
       p = '#' + p;
    vector<vector<int>> dp(n + 1,vector<int>(m + 1));
    
    dp[0][0] = 1;
    for(int i=1; i<=n; i++) dp[i][0] = 0;
    for(int i=1; i<=m; i++) dp[0][i] = 0;
    int flag=0;
    for(int i = 1; i <= m; i++){
        if(p[i] != '*') {
            flag = 0;
            break;
        }
        dp[0][i] = 1;
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++){
            if(s[i] == p[j] || p[j] == '?'){
                dp[i][j] = dp[i - 1][j - 1];
            }else if(p[j] == '*'){
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }else{
                dp[i][j] = 0;
            }
        }
    }

    return dp[n][m];
    }
};
