class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n+1, 1);  // Initialize dp with 1 since every element is a subset of itself
        vector<int> parent(nums.size(), -1);  // Initialize parent with -1 indicating no parent
            int max_len = 1, last_end = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if (dp[i] > max_len) {
                        max_len = dp[i];
                        last_end = i;
                    }
                }
            }
        }
        vector<int> lis;  // This will store the largest divisible subset
        // Trace back from the index of the last element in the largest subset
        while (last_end != -1) {
            lis.push_back(nums[last_end]);
            last_end = parent[last_end];
        }
        
        reverse(lis.begin(), lis.end());  // Reverse to return the subset in the correct order
        
        return lis;
    }
};
