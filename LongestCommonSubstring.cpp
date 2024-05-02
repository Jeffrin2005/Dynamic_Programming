int lcs(string &s1, string &s2){
   int n = s1.length();
   int m = s2.length();
   vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        s1 = "#" + s1;
        s2 = "#" + s2;
   dp[0][0] = 0;
   for(int i=1; i<=n; i++) dp[i][0] = 0;
   for(int i=1 ; i<=m; i++) dp[0][i] = 0;
   int ans = -1e9;
   for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++) {
         if (s1[i] == s2[j]) {
           dp[i][j] = 1 + dp[i - 1][j - 1];
           ans = max(dp[i][j], ans);
         } else dp[i][j] = 0;
       }
   }
   return ans;

}
