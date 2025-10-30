// dp = [
//   [1, -1, -1, -1],
//   [1,  1, -1, -1],
//   [1,  2,  1, -1],
//   [1,  3,  3,  1]

// ]

// We iterate over each column j from 0 to rowIndex (0 to 3 in this case).
// Iteration Details:

// 1. j = 0:
// check(3, 0, dp) is called.
// Base case if (row == 0 || col == row) does not apply.
// Recursive calls: check(2, 0, dp) and check(2, -1, dp).
// check(2, 0, dp) calls check(1, 0, dp) which returns 1 (base case).
// check(2, -1, dp) returns 0 (out of bounds).
// dp[3][0] is set to 1 (sum of 1 and 0).
// j = 1:
// check(3, 1, dp) is called.
// Recursive calls: check(2, 1, dp) and check(2, 0, dp).
// check(2, 1, dp) further calls check(1, 1, dp) and check(1, 0, dp), both returning 1.
// dp[3][1] is set to 3 (sum of 2 from check(2, 1, dp) and 1 from check(2, 0, dp)).
// 3. j = 2:
// Similar to j = 1, check(3, 2, dp) results in 3.
// j = 3:
// check(3, 3, dp) is called.
// Base case if (row == 0 || col == row) applies since col == row.

// dp[3][3] is set to 1.
//The result vector is filled based on the computed values in dp[3][...], resulting in [1, 3, 3, 1].
class Solution {
private:
    int check(int row, int col, vector<vector<int>>& dp) {
        if(row == 0 || col == row) return 1;
        if (dp[row][col] != -1) return dp[row][col];
        int left = (col > 0) ? check(row - 1, col - 1, dp) : 0;
        int right = (col < row) ? check(row - 1, col, dp) : 0; 
        dp[row][col] = left + right; 
        return dp[row][col];
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex + 1, vector<int>(rowIndex + 1, -1));
        vector<int> result(rowIndex + 1);
        for (int j = 0; j <= rowIndex; j++) {
            result[j] = check(rowIndex, j, dp);
        }
        return result;
    }
};
