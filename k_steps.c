int minimizeCost(int n, int k, vector<int>&height){
    vector<int> dp(n+1,0);
    dp[0]=0;
    for (int i=1;i<n;i++){
        int steps = INT_MAX;
        for (int j=1;j<=k;j++){
            if(i - j >= 0) {
              int jump = dp[i - j] + abs(height[i] - height[i - j]);
              steps = min(jump, steps);
            }

        }
        dp[i]=steps;

    }
    return dp[n-1];

}
