class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base cases: when there is only one pile between i and j (i == j)
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        // Fill the DP table
        for (int len = 2; len <= n; len++) { // length of the subarray
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                // Alice chooses the pile at i or j, and tries to maximize her score
                int pickLeft = piles[i];
                if (i + 1 <= j) {
                    pickLeft += min((i + 2 <= j ? dp[i + 2][j] : 0), dp[i + 1][j - 1]);
                }
                int pickRight = piles[j];
                if (i <= j - 1) {
                    pickRight += min(dp[i + 1][j - 1], (i <= j - 2 ? dp[i][j - 2] : 0));
                }
                dp[i][j] = max(pickLeft, pickRight);
            }
        }

        // Total sum of piles
        int totalSum = accumulate(piles.begin(), piles.end(), 0);

        // Alice's optimal score is dp[0][n-1]
        return dp[0][n-1] > totalSum - dp[0][n-1];
    }
};
