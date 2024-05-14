
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        int m = word.size();
        vector<int> dp(n+1, 0);
        dp[0] = 0;// no need of this 
        int max_k = 0;
        for (int i = 0; i < n; i++){
            // Check if the substring ending at i matches `word`
            if (i + 1 >= m && sequence.substr(i - m + 1, m) == word) {
                // i - m < 0 check if its currnt_substring_length is < 0 then dp[i] = 1; else we count and goes to 
                // goes to dp[i-m](extending out substring length  + 1);
                if (i - m < 0) {
                    dp[i] = 1;
                } else {
                    dp[i] = dp[i - m] + 1;
                }
                max_k = max(max_k, dp[i]);
            }
        }
        return max_k;
    }
};
