class Solution {
private:
    int check(vector<vector<int>>&matrix, int i, int j, int m, int n, vector<vector<int>>&dp){
           if (i < 0 || j < 0 || matrix[i][j] == 0) return 0;
        if(dp[i][j] != -1) return  dp[i][j];
        int top = check(matrix, i-1 , j , m,n , dp);
        int left = check(matrix,i, j-1 , m, n ,dp);
        int top_left = check(matrix, i - 1, j - 1 , m,  n , dp);
        int ans = 1 + min({top, left, top_left});
        dp[i][j] = ans;  

        return dp[i][j] ; 
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m , vector<int>(n , - 1));
        int cnt = 0 ;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 1){
                cnt+=check(matrix, i, j, m, n , dp);
                }
                
            }
        }
        return cnt; 
        
    }
};
