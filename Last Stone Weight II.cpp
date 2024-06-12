class Solution {
public:
   int lastStoneWeightII(vector<int>& stones) {
    int n = stones.size();
    vector<vector<int>> dp(n + 1, vector<int>(3001, INT_MAX));
    dp[0][0] = 0; 
    for (int i = 0; i < n; ++i) {
        for (int diff = 0; diff <= 3000; ++diff) {
            if (dp[i][diff] != INT_MAX) {
                int newDiffA = abs(diff + stones[i]);
                if (newDiffA <= 3000) {
                    dp[i + 1][newDiffA] = min(dp[i + 1][newDiffA], dp[i][diff]);
                }
                int newDiffB = abs(diff - stones[i]);
                if (newDiffB <= 3000) {
                    dp[i + 1][newDiffB] = min(dp[i + 1][newDiffB], dp[i][diff]);
                }
            }
        }
    }
    int result = INT_MAX;
    for (int diff = 0; diff <= 3000; ++diff) {
        if (dp[n][diff] != INT_MAX) {
            result = min(result, diff);
        }
    }

    return result;
}
};
