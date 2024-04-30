int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp (n+1,vector<int>(n+1,0));
	dp[0][0] = 0;
	// we have been given the 1 base indexing 
	      for(int i=1;i<=n;i++) dp[i][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j] = dp[i-1][j]; // not take 
			if(j>=i){// take {
				dp[i][j] = max(price[i-1]+dp[i][j-i],dp[i-1][j]);
			}
		}
	}
	return dp[n][n];
}
