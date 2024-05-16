class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(4, vector<int>(n + 1, 0));

        dp[0][0] = 1;
        for(int i=1; i<=n; i++) dp[1][i] = i;
        for (int i = 2; i <= 2; ++i) {  // Only need up to 2 eggs
            for (int j = 1; j <= n; ++j) {
                int mi = INT_MAX;
                for (int x = 1; x <= j; ++x){
                    int Break = dp[i - 1][x - 1];  // Egg breaks
                    int notBreak = dp[i][j - x];  // Egg does not break
                    int worst = 1 + max(Break, notBreak);  // 1 move plus the worst of the two scenarios
                    mi = min(mi, worst);
                }
                dp[i][j] = mi;
            }
        }

        return dp[2][n];
    }
};
