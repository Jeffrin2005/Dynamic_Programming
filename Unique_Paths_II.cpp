class Solution {
public:
        
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j] != 1){
                if(i==0&&j==0) {
                if(obstacleGrid[0][0]==0){
                 dp[i][j]=1;
            
                }else{
                    dp[i][j] = 0;
                }
                }else{
                    int down=0;
                    int right=0;
                    if(i>0 ) down =  dp[i-1][j];
                     if(j>0) right=dp[i][j-1];
                   
                   dp[i][j] = (down + right);
                }
                }
            }
        }

        return dp[n-1][m-1];
    }
};
