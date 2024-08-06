class Solution {
private:
// time comp = o(n*log(n))
// space comp = o(n);
    int check(int i, vector<int>&dp){
        if(i==0) return 0;
        if(dp[i] != -1) return dp[i];
        dp[i] = (i%2) + check(i/2, dp);
        return dp[i];
    }
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        vector<int>dp(n+1, -1);
        for(int i=0; i<=n; i++){
            ans[i] = check(i,dp);
        }
        return ans;
        
    }
};
