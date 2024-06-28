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
        return check(s, t, 0, 0 , dp);
    }
};
