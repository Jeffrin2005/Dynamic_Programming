class Solution {
public:

    int solve(string &s, vector<int>&nums, int i, int prev, vector<vector<int>>&dp){
        int n= nums.size();
        if(i >= n) return 0;
        int &ret = dp[i][prev];
        if(ret != -1) return ret;

        
        int incl=1e9;
        if(prev==-1 or  s[i] - 'a' != prev) incl=solve(s, nums, i+1, s[i]-'a', dp);
        int excl = nums[i] + solve(s, nums, i + 1, prev, dp);
        return dp[i][prev]=min(incl, excl);
    }
    int minCost(string s, vector<int>& nums){
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(27, -1));
        return solve(s,nums,0,26,dp);
    }
};
