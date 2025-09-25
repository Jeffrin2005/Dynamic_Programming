class Solution {
public:
    bool divisorGame(int n) {
        vector<int> dp(n + 1, 0); 
        dp[1] = 0; // Base case: if n = 1, the player loses
        for (int i = 2; i <= n;i++){
            for (int x = 1; x < i; x++){
                
                if (i % x == 0 && dp[i - x] == 0) { // If the opponent loses from state i - x
                    dp[i] = 1; // Current player wins
                    break;
                }
                
            }
        }
        return dp[n] == 1; // Return true if dp[n] is 1 (Alice wins)
    }
};
