class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int flag = 0; flag <= 1; flag++) {
                if (s[i] == '1' && flag) {
                    dp[i][flag] = min(1 + dp[i + 1][flag], dp[i + 1][0]);
                } else if (s[i] == '0' && flag == 0) {
                    dp[i][flag] = 1 + dp[i + 1][flag];
                } else {
                    dp[i][flag] = dp[i + 1][flag];
                }
            }
        }
        return dp[0][1];
    }
};
