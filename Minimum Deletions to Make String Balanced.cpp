class Solution {
public:
    int minimumDeletions(string s) {
        s ='#' + s;
        int n = s.size(); 
        vector<int> dp(n + 1);
        int b = 0; 
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'a'){
                dp[i] = min(1 + dp[i-1], b); 
            } else {
                dp[i] = dp[i-1]; 
                ++b;
            }
        }
        return dp[n];
    }
};

