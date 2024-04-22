#include <bits/stdc++.h>
#define ll long long 
class Solution {
public:
    int uniquePaths(int m, int n) {
            vector<vector<ll>>dp(m+1,vector<ll>(n+1, -1));
            dp[0][0] = 1;
            for(ll i=0; i<m; i++){
                for(ll j=0; j<n; j++){
                    if(i==0 or j==0) dp[i][j] = 1;
                    else  dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
            return dp[m-1][n-1];
    }
};
