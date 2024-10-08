class Solution {
public:
    int func(int i,int j,vector<vector<int>> &a,vector<vector<int>> &dp,int n){
            if(i==n-1) return a[i][j];  
        if(dp[i][j]!=-1) return dp[i][j];
        int path1= a[i][j] + func(i + 1,j , a , dp , n);
        int path2 = a[i][j] + func(i + 1,j + 1 , a , dp , n);
        return dp[i][j] = min(path1,path2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int> (n,-1));
        return func(0,0,triangle,dp,n);
    
        
    }
};// TABULATION
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
           int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int j = 0; j < n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i = n-2; i >= 0; --i){
            for(int j = 0; j <= i; ++j){
                int path1 = triangle[i][j] + dp[i+1][j];
                int path2 = triangle[i][j]  + dp[i+1][j+1];
                dp[i][j] = min(path1,path2);
              //  dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }

        // The top element now contains the minimum path sum
        return dp[0][0];
    }
};
