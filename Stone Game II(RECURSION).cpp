class Solution {

    
private:
    int n;
    int dp[2][101][101];
    
    int solveForAlice(int i, int player, int M, vector<int> &piles){
        if(i>=n) return 0;
        
        if(dp[player][i][M] != -1) return dp[player][i][M];
        
        int stones = 0;
        int  result;
    if (player == 1) {
    result = -1;  // Initialize result for Alice's turn to the smallest possible value because she wants to maximize her score.
} else {
    result = INT_MAX;  // Initialize result for Bob's turn to the largest possible value because he wants to minimize Alice's score.
}  
        for(int X=1; X<=min(2*M, n-i); X++){
            if(player == 1){
                stones += piles[i+X-1];
                result = max(result, stones + solveForAlice(i+X, 0, max(M, X), piles));
            }else{
                result = min(result, solveForAlice(i+X, 1, max(M, X), piles));
            }
        }
        
        return dp[player][i][M] = result;
    }
    
public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));
        
        return solveForAlice(0, 1, 1, piles);
    }
};
