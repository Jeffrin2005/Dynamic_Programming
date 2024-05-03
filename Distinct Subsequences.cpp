#include <bits/stdc++.h>
#define ll long  
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        s = '#' + s;
        t = '#' + t;
        vector<vector<double>>dp(n+1, vector<double>(m+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++) dp[i][0] = 1;
        for(int j=1; j<=m; j++) dp[0][j] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dp[i][j] = dp[i-1][j];// not take (if s[i] != t[j]) dp[i][j] = dp[i-1][j];
                if(s[i] == t[j]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; // take 
            }
        }    

        return (int)dp[n][m];
    }
};
