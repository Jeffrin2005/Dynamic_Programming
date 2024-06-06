#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(2,-1));
        dp[n][0]  = 0;
        dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--){
            // When subidx is 0, we consider adding nums[i]
            dp[i][0] = max(nums[i] + dp[i + 1][1], dp[i + 1][0]);
            // When subidx is 1, we consider subtracting nums[i]
            dp[i][1] = max(-nums[i] + dp[i + 1][0], dp[i + 1][1]);
        }
        return dp[0][0];
    }
};
