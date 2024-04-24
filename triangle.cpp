#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(triangle); // Copy triangle to dp for initialization

        // Start from the second to last row and move upwards
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                // Update dp table by choosing the minimum path from the row below
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }

        // The top element now contains the minimum path sum
        return dp[0][0];
    }
};
