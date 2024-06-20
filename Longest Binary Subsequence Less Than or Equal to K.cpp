

class Solution {
public:

    int f(string &s, int k, int i, std::vector<int>& dp,int n ) {
        if (i == 0)  return 0;
        if (dp[i] != -1) return dp[i];
        // take
        int x = 0;
        if ((s[i-1] - '0') * pow(2, n - i) <= k){
            x = 1 + f(s, k - (s[i-1] - '0') * pow(2, n - i), i - 1, dp, n );
        }
        // not take
        int y = f(s, k, i - 1, dp, n );
         dp[i] = std::max(x, y);

         return dp[i];
    }

    int longestSubsequence(string &s, int k) {
        int n = s.size();
   vector<int> dp(n + 1, -1);
        return f(s, k, n, dp, n);
    }
};
