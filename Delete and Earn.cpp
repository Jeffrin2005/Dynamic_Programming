class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> sum(n + 1, 0); 
        for (int num : nums) {
            sum[num + 1] += num; 
        }
        vector<int> dp(n + 1, 0); 
        dp[1] = sum[1];
        for (int i = 2; i <= n; i++){ 
            int pick = sum[i];
            if(i > 2){
                pick += dp[i-2]; 
            }
            int notPick = dp[i-1]; 
            dp[i] = max(pick, notPick);
        }
        return dp[n]; 
    }
};
