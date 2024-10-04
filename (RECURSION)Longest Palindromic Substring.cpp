class Solution {
    
private:
    vector<vector<int>>dp;
    //check if s[i...j] is a palindrome
    bool isPalindrome(string& s, int i, int j){
        if (i > j) return false;
        if (i == j) return true;
        if (s[i] != s[j]) return false;
        // aa  , i = 0, j = 1
        if (j - i == 1) return true;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //  check for the inner substring
        dp[i][j] = isPalindrome(s, i + 1, j - 1) ? 1 : 0;
        return dp[i][j];
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        int maxLength = 1;
        int start = 0;
        // Iterate through all possible substrings
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                if (isPalindrome(s, i, j)){
                    if (j - i + 1 > maxLength){
                        maxLength = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start, maxLength);
    }
};
