class Solution{
private:
    bool check(int i, vector<int>&dp){
        if(i == 1) return false;
        if(dp[i] != -1) return dp[i];
        for(int x=1; x<i; x++){
            if(i%x == 0){
                if((check(i - x, dp) == false)){
                    dp[i] = 1;
                    return true; 
                 }
            }
        }
        dp[i] = 0;
        return false; 
    }public:
    bool divisorGame(int n) {
        vector<int>dp(n + 1, -1);
        bool ans = check(n , dp);
        return ans; 
        }           // dry run 
};
// Index:   0   1   2   3   4
// DP:     [-1, -1, -1, -1, -1]  Initial state, -1 means "not computed yet"

//  Base Case
// For i = 1, there are no valid moves, so the player loses:

// Index:   0   1   2   3   4
// DP:     [-1,  0, -1, -1, -1]  At index 1, set to 0 (player loses)

//  Compute for i = 2
// Check possible moves:
// x = 1 leads to state 2 - 1 = 1. Since dp[1] = 0 (opponent loses), current player wins:

// Index:   0   1   2   3   4
// DP:     [-1,  0,  1, -1, -1]  At index 2, set to 1 (player wins)

// Compute for i = 3
// Check possible moves:
// x = 1 leads to state 3 - 1 = 2. Since dp[2] = 1 (opponent wins), continue checking:
// No other divisors of 3 less than 3 lead to a win for the current player:

// Index:   0   1   2   3   4
// DP:     [-1,  0,  1,  0, -1]  At index 3, set to 0 (player loses)

//  Compute for i = 4
// Check possible moves:
// x = 1 leads to state 4 - 1 = 3. Since dp[3] = 0 (opponent loses), current player wins:
// x = 2 leads to state 4 - 2 = 2. Since dp[2] = 1 (opponent wins), this move does not help in determining a win

// Index:   0   1   2   3   4
// DP:     [-1,  0,  1,  0,  1]  At index 4, set to 1 (player wins)

// final dp table 
// Index:   0   1   2   3   4
// DP:     [-1,  0,  1,  0,  1]
// dp[1] = 0: Player loses if starting with 1.
// dp[2] = 1: Player wins if starting with 2.
// dp[3] = 0: Player loses if starting with 3.
// dp[4] = 1: Player wins if starting with 4.
