class Solution {
public:
// time comp =o(n) space comp = o(n)
    vector<int> countBits(int n) {
      vector<int>dp(n + 1, 0);
        dp[0] = 0; // Base case: there are no 1s in the binary representation of 0
        for(int i = 1; i <= n; i++){
            // The number of 1s in i is the number of 1s in i/2 plus 1 if i is odd
            dp[i] = (i%2) + dp[i/2];
        }
        return dp;  
        
        
    }
};
