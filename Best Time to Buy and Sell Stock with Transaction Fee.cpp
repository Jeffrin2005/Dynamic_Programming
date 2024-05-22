class Solution {
public:
    int maxProfit(vector<int>& p, int fee){
        int n = p.size();
        vector<vector<int>>dp(n+1,vector<int>(2));
        for(int i=0; i<n; i++) dp[0][0] =0;
        for(int i=n-1; i>=0; i--){
            for(int x=0; x<=1; x++){
                if(x){
                    dp[i][x] = max(-p[i] + dp[i+1][0] , dp[i+1][1]);
                }else{
                    dp[i][x] = max(p[i] - fee + dp[i+1][1], dp[i+1][0]);
                }
            }
        }
        
        return dp[0][1];
    }
};
