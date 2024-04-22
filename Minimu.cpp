#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vvi cost(m, vi(11, 0)); 
        // Fill cost matrix
        for(int col = 0; col < m; ++col) {
            for(int j = 0; j < 10; ++j) {
                for(int row = 0; row < n; ++row) {
                    if(grid[row][col] != j) {
                        cost[col][j] += 1;
                    }
                }
            }
        }
        
        vector<vector<ll>> dp(m, vector<ll>(11, 1e9)); 
        
        for(int j = 0; j < 10; ++j) {
            dp[0][j] = cost[0][j];
        }
        
        // Fill DP table
        for(int col = 1; col < m; ++col) {
            for(int j = 0; j < 10; ++j) { 
                for(int k = 0; k < 10; ++k) {
                    if(j != k) { 
                        dp[col][j] = min(dp[col][j], dp[col-1][k] + cost[col][j]);
                    }
                }
            }
        }
        \
        ll ans = *min_element(dp[m-1].begin(), dp[m-1].end());
        return ans;
    }
};
