class Solution {
public:
    int check(string& s, int i, int n, vector<int>& dp){
        // If current character is '0', it cannot be decoded
        if(i < n && s[i] == '0') return 0;
        // If we've reached the end of the string, it's a valid decoding
        if(i >= n) return 1;
        if(dp[i] != -1) return dp[i];
        int ways = 0;
        // single digit 1 to 9 = A - I
        // double digit 10 to 26  = J - Z 
//         Any number starting with '0' is invalid (e.g., "06").
// Numbers greater than "26" (e.g., "27", "30") cannot be decoded as two-digit numbers.

        // Pick single digit
        if(s[i] != '0'){// for single character if i>=n => no of ways = 1,   so ways = check(s,i+1,n,dp) 
            ways += check(s, i + 1, n, dp);
        }       
        // Pick two digits if valid
        if(i + 1 < n && ((s[i] == '1' && s[i + 1] <= '9') or (s[i] == '2' && s[i + 1] < '7'))){
            ways += check(s, i + 2, n, dp);
        }
               
        return dp[i] = ways;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return check(s, 0, n, dp);
    }
};
