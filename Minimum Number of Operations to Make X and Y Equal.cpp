class Solution {
public:
    int solve(int x, int y, vector<int>& dp) {
        if (x <= y) return y - x;
        if (dp[x] != -1) return dp[x];
        int res = abs(x - y);                                 // case 1
        res = min(res, 1 + x % 5 + solve(x / 5, y, dp));      // case 2
        res = min(res, 1 + (5 - x % 5) + solve(x / 5 + 1, y, dp)); // case 3
        res = min(res, 1 + x % 11 + solve(x / 11, y, dp));   // case 4
        res = min(res, 1 + (11 - x % 11) + solve(x / 11 + 1, y, dp)); // case 5
        return dp[x] = res;
    }

    int minimumOperationsToMakeEqual(int x, int y) {
        vector<int> dp(10011, -1); 
        return solve(x, y, dp);
    }
};
