class Solution {
public:
    int minCost(string s, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(27, 1e9));
        for (int j = 0; j < 27; j++) {
            dp[n][j] = 0;
        }
        for(int i = n - 1; i >= 0; i--){
            for(int prev = 0; prev < 27; prev++){
                // Exclude current character
                int excl = nums[i] + dp[i + 1][prev];
                // Include current character, only if it does not match the previous character
                int incl = 1e9;
                int currentChar = s[i] - 'a';
                if(prev == 26 || currentChar != prev){
                    incl = dp[i + 1][currentChar];
                }
                dp[i][prev] = min(incl, excl);
            }
        }
        return dp[0][26];
    }
};
