class Solution {
private:
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int pick = solve(nums, i+2, dp) + nums[i];
        int nonPick = solve(nums, i+1, dp);
        return dp[i] = max(pick, nonPick);

    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return solve(nums, 0, dp);
    }
};// TABULATION 
class Solution {
public:
    int rob(vector<int>& nums) {
         int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int>dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            // Decide whether to rob the current house or not
            int pick = dp[i-2] + nums[i];
            int not_pick = dp[i-1];
            dp[i] = max(pick, not_pick);
        }
        
        return dp[n-1];
    }
};
