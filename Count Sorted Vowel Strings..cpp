// Rows (i): Each row corresponds to a starting vowel. The vowels are indexed as follows based on the string "aeiou":
// 0: 'a'
// 1: 'e'
// 2: 'i'
// 3: 'o'
// 4: 'u'
// Columns (n): Each column corresponds to the length of the vowel strings being considered.
// For example, dp[i][2] would represent the number of vowel strings of length 2 starting with the vowel at index i.

// If you are trying to count strings of length 3 starting with 'a', (n - 1) ;
//you make a recursive call to count strings of length 2 starting with 'a'. This process continues until you reach strings of length 0, 
//which are the base cases and are known to be 1 (the empty string).

class Solution {
public:
    int count(int i, int n, string &vowels, std::vector<std::vector<int>>& dp) {
        if (n == 0) return 1; // i = character, n = length  
        if (i >= 5) return 0;
        if (dp[i][n] != -1) return dp[i][n];
        int pick,not_pick;
         pick= count(i, n-1, vowels, dp);
        not_pick =  count(i+1, n, vowels, dp);
        dp[i][n] =  pick + not_pick;
        return dp[i][n];
    }

    int countVowelStrings(int n){
        string vowels = "aeiou";
        vector<vector<int>> dp(5,vector<int>(n + 1, -1));
        return count(0, n, vowels, dp);
    }
};
// tabulation
class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(6, 0));
        for (int j = 1; j <= 5; j++) {
            dp[0][j] = 1;// base case if we reach n return 1
        }
        // a e i o u 
        // n = length (i) , charc = a,e,i,o,u (j)
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= 5; j++){  // O(5)
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
   
   

