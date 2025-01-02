#include <vector>
using namespace std;

class Solution {
private:
    int check(int row, int col, vector<vector<int>>& dp) {
        if (row == 0 || col == row) return 1; 
        
        if (dp[row][col] != -1) return dp[row][col];
        int left = (col > 0) ? check(row - 1, col - 1, dp) : 0; 
        int right = (col < row) ? check(row - 1, col, dp) : 0; 

        dp[row][col] = left + right; 
        return dp[row][col];
        
    }
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(i + 1, -1); 
        }
        vector<vector<int>> result(n);
        for (int i = 0; i < n; i++) {
            result[i].resize(i + 1); 
            for (int j = 0; j <= i; j++) {
                result[i][j] = check(i, j, dp); 
            }
        }
        return result;
    }
};
