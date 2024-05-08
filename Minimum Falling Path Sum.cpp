class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));

        // Initialize the first row of dp with the first row of the matrix
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }
       
        // Fill the dp table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Directly update dp[i][j] with the value directly above
                dp[i][j] = matrix[i][j] + dp[i-1][j];

                // Check diagonally left and update if it results in a smaller path sum
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i-1][j-1]);
                }

                // Check diagonally right and update if it results in a smaller path sum
                if (j < n - 1) {
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i-1][j+1]);
                }
            }
        }

        // Find the minimum path sum in the last row
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[n-1][i]);
        }

        return ans;
    }
};
