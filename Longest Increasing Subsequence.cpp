class Solution {
private:
    vector<vector<int>> memo;
    int findLIS(int previousIndex, int currentIndex, vector<int>& nums){
        if (currentIndex == nums.size()){
            return 0;
        }
        if(memo[previousIndex + 1][currentIndex] != -1) {
            return memo[previousIndex + 1][currentIndex];
        }
        int include = 0;
        if (previousIndex == -1 || nums[previousIndex] < nums[currentIndex]) {
            include = 1 + findLIS(currentIndex, currentIndex + 1, nums);
        }
//  During the recursion, previousIndex can range from -1 (no elements included) to n-1 (last element in the array), where n is the size of the input array nums.
        // Option 2: Exclude the current element and move to the next
        int exclude = findLIS(previousIndex, currentIndex + 1, nums);

        // Store the maximum of include and exclude in the memo table
        memo[previousIndex + 1][currentIndex] = max(include, exclude);
        return memo[previousIndex + 1][currentIndex];
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memo = vector<vector<int>>(n+1 , vector<int>(n+1, -1));
        return findLIS(-1, 0, nums);
    }
};// TABULATION
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 1); 
       dp[0] = 1;
        int max_lis = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int exclude = dp[i];
                int include = dp[j] + 1; 
                if( nums[j] < nums[i]){
                    dp[i] = max(exclude,include); 
                }
            }
            max_lis = max(max_lis,dp[i]);
        }
        return max_lis;
    }
};
