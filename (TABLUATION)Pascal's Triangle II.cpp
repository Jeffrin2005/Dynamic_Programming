class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex + 1, vector<int>(rowIndex + 1, 0));
        for (int i = 0; i <= rowIndex; i++) {
            dp[i][0] = 1; // First element of each row is 1
            dp[i][i] = 1; // Last element of each row is 1
        }
        for (int i = 1; i <= rowIndex; i++){
            for (int j = 1; j < i; j++){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }

        // Extract the rowIndex-th row
        vector<int> result(rowIndex + 1);
        for (int j = 0; j <= rowIndex; j++) {
            result[j] = dp[rowIndex][j];
        }

        return result;
    }
};
