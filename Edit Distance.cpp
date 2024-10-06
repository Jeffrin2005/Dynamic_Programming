class Solution {
private:
// i for word1, j for word2 , loop from n to 0 and m to 0 
    int check(int i, int j,  string &word1,  string &word2, vector<vector<int>>&dp){
        // Base cases
        if(i == 0) return j; //You have exhausted all characters in word1. This means word1 is effectively empty up to index i = 0, To convert an empty word1 into the first j characters of word2, you need to insert all j remaining characters from word2 into word1.
        if(j == 0) return i; //  This means word2 is effectively empty up to index j = 0.o convert the first i characters of word1 into an empty word2, you need to delete all i remaining characters from word1.
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i - 1] == word2[j - 1]){
            // Characters match, move to the next pair
            dp[i][j] = check(i - 1, j - 1, word1, word2, dp);
        }
        else{
            // Characters don't match, consider all three operations
            int insertOp = check(i, j - 1, word1, word2, dp);
            int deleteOp = check(i - 1, j, word1, word2, dp);
            int replaceOp = check(i - 1, j - 1, word1, word2, dp);
            dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
        }
        return dp[i][j];
    }
public:
    int minDistance(string word1, string word2){
        int n = word1.size();
        int m = word2.size();// word1 => word2 ,  // n => m 
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
        return check(n,m,word1,word2,dp);
    }
};// TABULATION
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = i;  // Deleting all characters from word1 to match an empty word2
        for (int j = 0; j <= m; j++) dp[0][j] = j;  // Inserting all characters of word2 to match an empty word1
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];  
                } else {
                    int insertOp = dp[i][j - 1]; 
                    int deleteOp = dp[i - 1][j]; 
                    int replaceOp = dp[i - 1][j - 1];  
                    dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
                }
            }
        }

        return dp[n][m];
    }
};
