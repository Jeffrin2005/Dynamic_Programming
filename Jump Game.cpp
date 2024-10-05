
class Solution {
public:
    bool canJumpFromPosition(int i,  vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if(i == n - 1){
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int furthestJump = min(i + nums[i], (int)(n - 1));
        for(int nextPos = i + 1; nextPos <= furthestJump; nextPos++){
            if(canJumpFromPosition(nextPos, nums, dp)){
                dp[i] = true; 
                return dp[i]; 
            }
        }
        dp[i] = false; // not possible to reach;
        return dp[i];  
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return canJumpFromPosition(0, nums, dp);
    }
};// TABULATION
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // Initialize DP array with false (unreachable)
        vector<bool> dp(n, false);
        dp[0] = true; // Base case: first position is always reachable
        // Iterate from the first position to the last
        for (int i = 0; i < n; i++) {
         if (dp[i] == false) continue; // If current position is not reachable, skip it

            int furthestJump = min(i + nums[i], n - 1);
            // Mark all positions reachable from current position as true
            for (int j = i + 1; j <= furthestJump; j++) {
                if(dp[j] == false){ // Only update if not already reachable, we initial vector with fals
                    dp[j] = true;
                }
            }
        }
        return dp[n - 1];
    }
};
