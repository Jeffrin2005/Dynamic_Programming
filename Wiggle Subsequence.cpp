class Solution {
private:
    int fun(vector<int>& nums, int index, int prevSign, vector<vector<int>>& dp) {
        int n = nums.size();
        if(index == n) return 0;
        if(dp[index][prevSign] != -1) return dp[index][prevSign];
        int maxLength = 1; // At least the current element
        // Explore all possible next elements to extend the wiggle
        for(int i = index + 1; i < n; i++) {
            int diff = nums[i] - nums[index];
            if(diff > 0 && (prevSign == 0 || prevSign == 2)){// prevsign=2 => Alternating After a Negative Difference
            // so extend the length of sequence 
                maxLength = max(maxLength, 1 + fun(nums, i, 1, dp));
            }else if(diff < 0 && (prevSign == 0 || prevSign == 1)){
                maxLength = max(maxLength, 1 + fun(nums, i, 2, dp));
            }
        }
        return dp[index][prevSign] = maxLength;
    }
    public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(3, -1));
        // Start recursion from index 0 with no previous difference (0)
        return max(fun(nums, 0, 0, dp), 1);
    }
};/// TABULATION 

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        // Define dp[i][j]
        // j = 0: No previous difference
        // j = 1: Previous difference was positive
        // j = 2: Previous difference was negative
        vector<vector<int>> dp(n, vector<int>(3, 1));
        for(int i = n - 1; i >= 0; i--){
            for(int prevSign = 0; prevSign < 3; prevSign++){
                for(int j = i + 1; j < n;j++){
                    int diff = nums[j] - nums[i];
                    if(diff > 0 && (prevSign == 0 || prevSign == 2)){
                        dp[i][prevSign] = max(dp[i][prevSign], 1 + dp[j][1]);
                    }
                    else if(diff < 0 && (prevSign == 0 || prevSign == 1)){
                        dp[i][prevSign] = max(dp[i][prevSign], 1 + dp[j][2]);
                    }
                }
            }
        }
        
        // Find the maximum length starting from any index with no previous difference
        int maxLength = 1;
        for(int i = 0; i < n; ++i){
            maxLength = max(maxLength, dp[i][0]);
        }
        
        return maxLength;
    }
};
