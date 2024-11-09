class Solution { // USING TABULATION 
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, 0);
        int ans = 0;
        for(int i = 2; i < n; i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                dp[i] = dp[i - 1] + 1;
            }else{
                dp[i]  = 0;
            }
        }
        for(auto&x : dp) ans+=x;
        return ans;
    }
};// USING RECURSION + MEMO 
class Solution {
private:

    int countArithmeticSlices(vector<int>& nums, int i, vector<int>& dp) {
        // Base case: If 'end' is less than 2, there are not enough elements to form a slice.
        if (i < 2) return 0;
        if (dp[i] != -1) return dp[i];
        // Check if the current triplet forms an arithmetic slice.
        if ((nums[i] - nums[i - 1]) == (nums[i - 1] - nums[i - 2])) {
            // One valid slice is found ending at 'end'.
            // Additionally, any slices ending at 'end - 1' can be extended by the current element.
            dp[i] = 1 + countArithmeticSlices(nums, i - 1, dp);
        } else {
            // If the current triplet does not form an arithmetic slice, no slices end at 'end'.
            dp[i] = 0;
        }
        return dp[i];
    }
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
       vector<int> dp(n, -1);
        int totalSlices = 0;
        for(int i = 2; i < n; i++){
            totalSlices+=countArithmeticSlices(nums, i, dp);
        }

        return totalSlices;
    }
};
