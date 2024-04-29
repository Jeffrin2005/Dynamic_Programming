
class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
           vector<int>v(n + 1);
        for(int i = 0; i < n; i++){
            v[i + 1] = coins[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(amount+1));
        dp[0][0] = 1;
            for(int i=1;i<=n;i++) dp[i][0]=1;

        for( int i = 1; i <= n; i++ ){

            for( int j = 0; j <= amount; j++ ){
               // notake = dp[i-1][j];
               dp[i][j] = dp[i-1][j];
                if( v[i] <= j){// take 
                  dp[i][j] = dp[i][j - v[i]] + dp[i-1][j];
                }
            }
        }
        
        return dp[n][amount];

       
    }

};
