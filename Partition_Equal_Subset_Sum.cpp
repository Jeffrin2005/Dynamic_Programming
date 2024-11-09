#include <bits/stdc++.h>
#define nl '\n'
#define ll long long 

class Solution {
private:
    bool canPartitionHelper(vector<int>& nums, int target, int index, vector<vector<int>>& memo) {
        if (target == 0) return true;
        if (target < 0 || index >= nums.size()) return false;
        // Check if the result for this subproblem is already computed
        if (memo[index][target] != -1) return memo[index][target];
        // Recursively try to include the current number in the subset
        bool include = canPartitionHelper(nums, target - nums[index], index + 1, memo);
        // Recursively try to exclude the current number from the subset
        bool exclude = canPartitionHelper(nums, target, index + 1, memo);
        memo[index][target] = include || exclude;
        return memo[index][target];
    }

public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;
        // If total sum is odd, we cannot partition it into two equal subsets
        if (totalSum % 2 != 0) return false;
        int target = totalSum / 2;
        vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1)); // Corrected line
        return canPartitionHelper(nums, target, 0, memo);
    }
};// TABULATION
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n + 1);
// converting 1 base indexing 
        for(int i = 0; i < (int)(nums.size()); i++){
            v[i + 1] = nums[i];
        }
        int sum = 0;
        for (auto i : nums) {
            sum += i;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int m = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = true ;
        for(int i=1; i<=n; i++) dp[i][0] = 1;
        for (int i = 1; i <= n; i++){
            for(int j = 0; j <= m; j++) {
                dp[i][j] = dp[i-1][j]; // not take 
                if(v[i] <= j) {// take || not takee
                    dp[i][j] = dp[i-1][j-v[i]] || dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};
