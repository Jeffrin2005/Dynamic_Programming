class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
       int m = grid.size(), n = grid[0].size();
        //create a dp array of size m*n
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0]=0;
        int c1,c2;
        int res=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    continue;
                }
                if(i==0){
                    dp[i][j]=max(grid[i][j]-grid[i][j-1],grid[i][j]-grid[i][j-1]+dp[i][j-1]);
                    res=max(res,dp[i][j]);
                }
                else if(j==0){
                    dp[i][j]=max(grid[i][j]-grid[i-1][j],grid[i][j]-grid[i-1][j]+dp[i-1][j]);
                    res=max(res,dp[i][j]);
                }
                else{
                    c1=max(dp[i][j-1]+grid[i][j]-grid[i][j-1],dp[i-1][j]+grid[i][j]-grid[i-1][j]);
                    c2=max(grid[i][j]-grid[i][j-1],grid[i][j]-grid[i-1][j]);
                    dp[i][j]=max(c1,c2);  
                    res=max(res,dp[i][j]); 
                }


            }
          
        }
          return res;
    }
            
};
