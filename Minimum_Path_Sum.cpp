class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));

       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(i==0 && j==0){
                    dp[i][j]+=grid[i][j];
                }
                else{
                    int dw=grid[i][j];
                   if(i>0) dw+=dp[i-1][j];
                   else{
                       dw+=1e9;
                   }
                   int rt=grid[i][j];
                   if(j>0) rt+=dp[i][j-1];
                   else{
                       rt+=1e9;
                   }
                   dp[i][j]=min(dw,rt);
                }
                 
            }
        }
        return dp[n-1][m-1];
    }
};
