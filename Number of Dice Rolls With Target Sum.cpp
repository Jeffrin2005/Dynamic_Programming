class Solution {
public:
    int MOD = 1000000007;
    int numRollsToTarget(int n, int k, int target) { 
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        for (int dice = 1; dice <= n; dice++){ 
            for (int t = 1; t <= target; t++){
                long long int ans = 0;
                for (int i = 1; i <= k; i++){
                    if(t - i >= 0){
                        ans+=dp[dice - 1][t - i];
                         ans%=1000000007;
                    }
                }
                dp[dice][t] = ans;
            }
        }
        return dp[n][target];
    }
};
