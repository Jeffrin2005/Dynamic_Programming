class Solution {
private:
    // s_index = i;

    // t_index = j; 
    bool check(string &s, string &t,int i, int j, vector<vector<int>>&dp){
        if(i == s.size()) return true;
        if(j == t.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            dp[i][j] = check(s, t,i + 1, j + 1, dp);
        }else{
            dp[i][j] = check(s, t , i, j + 1, dp );
        }
        return dp[i][j];
    }
public:
    bool isSubsequence(string s, string t) {
        int n= s.size();
        int n1 = t.size(); 
        vector<vector<int>>dp(n, vector<int>(n1 , - 1));
        int ans =  check(s, t, 0, 0 , dp);
        return ans; 
    }
};

// TABULATION
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        for(int i = 0; i <= m; i++) dp[i][0] = false; // base case if we reach last index of string t 
        for(int i = 0; i <= n; i++) dp[0][i] = true; // base case if we reach last index of string s 
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if (s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1]; 
                }else{
                    dp[i][j] = dp[i][j - 1]; 
                }
            }
        }

        return dp[m][n];
    }
};
