

class Solution {
public:
    int twoEggDrop(int n) {
        // Create a memoization table initialized with -1 (indicating uncomputed values)
        std::vector<std::vector<int>> memo(3, std::vector<int>(n + 1, -1));
        return eggDrop(2, n, memo);
    }

private:
    int eggDrop(int eggs, int floors, std::vector<std::vector<int>>& memo) {
        // Base cases
        if (floors == 0 || floors == 1) return floors;
        if (eggs == 1) return floors;

        // Check if already computed
        if (memo[eggs][floors] != -1) return memo[eggs][floors];

        int minDrops = INT_MAX;

        // Use a linear search to find the minimum number of drops needed in the worst case
        for (int x = 1; x <= floors; ++x) {
            int breakCount = eggDrop(eggs - 1, x - 1, memo); // Egg breaks
            int noBreakCount = eggDrop(eggs, floors - x, memo); // Egg doesn't break

            // We need the worst case from both scenarios
            int worst = 1 + std::max(breakCount, noBreakCount);

            // We are minimizing the worst case
            minDrops = std::min(minDrops, worst);
        }

        // Memoize and return the result
        memo[eggs][floors] = minDrops;
        return minDrops;
    }
};
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
