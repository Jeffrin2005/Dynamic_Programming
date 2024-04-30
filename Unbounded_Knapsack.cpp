int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
      vector<int>v1(n + 1);
            vector<int>v2(n + 1);
        for(int i = 0; i < n; i++){
            v1[i + 1] = profit[i];
        }
          for(int i = 0; i < n; i++){
            v2[i + 1] = weight[i];
        }
         dp[0][0] = 0;
             for(int i=1;i<=n;i++) dp[i][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=w;j++){
            dp[i][j] = dp[i-1][j]; // not take 
            if(j >= v2[i]){// take 
                dp[i][j] = max(v1[i] + dp[i][j-v2[i]] ,  dp[i-1][j]);
            }
        }
    }
    return dp[n][w];
}
