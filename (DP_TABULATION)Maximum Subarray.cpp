class Solution {
public:
    int maxSubArray(vector<int>& v) {
         int n = v.size();
        if(n == 0) return 0;
        
       //dp[i] represents the maximum subarray sum ending at index i
        vector<int>dp(n, 0);
        dp[0] = v[0];
        int maxi = dp[0];
        
        for(int i = 1; i < n; ++i){
            // Decide whether to extend the previous subarray or start a new subarray at current index
            dp[i] =max(v[i], dp[i-1] + v[i]);
            maxi = max(maxi, dp[i]);
        }
        
        return maxi;
        
    }
};
