class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(6, 0));
        for (int j = 1; j <= 5; ++j) {
            dp[0][j] = 1;// base case if we reach n return 1
        }
        // a e i o     u 
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= 5; ++j){  // O(5)
                // /        take        +   notake 
                // pick = 	pick= count(i, n-1, vowels);
                //  notPick= count(i+1, n, vowels);

                //       /        nottake    +    take 
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[n][5];
    }
};
   
   
