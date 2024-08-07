

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>dp(numRows);
        
        for(int i = 0; i < numRows; i++){
            dp[i].resize(i + 1);  // Resize current row to have 'i + 1' elements
            dp[i][0] = dp[i][i] = 1;  // First and last elements are always 1
            // Fill in the middle elements using the sum of two elements directly above
            for(int j = 1; j < i; j++){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        return dp;
    }
};
