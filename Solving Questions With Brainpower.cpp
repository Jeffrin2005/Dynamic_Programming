#include <bits/stdc++.h>
#define ll long long 

class Solution {
public:
    ll mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<ll> dp(n + 1, 0); 
        
        for (int i = n - 1; i >= 0; i--) {
            ll skip = dp[i + 1]; 
            ll take = q[i][0]; 
            if (i + q[i][1] + 1 < n) {
                take += dp[i + q[i][1] + 1]; 
            }
            dp[i] = max(take, skip); 
        }

        return dp[0];
    }
};
