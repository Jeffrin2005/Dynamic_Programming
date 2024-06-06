class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> v1(n + 1);
        for(int i = 0; i < n;i++){
            v1[i + 1] = nums[i];
        }
        vector<int>dp1(n + 1, 0); // dp1 maxima subarary 
        vector<int>dp2(n + 1, 0); // dp2 minima subarray 
        dp1[0] = 0;
        dp2[0] = 0;
        int ans = INT_MIN;
        for (int i = 1; i <=n; i++){
            dp1[i] = max(v1[i], dp1[i - 1] + v1[i]);
            dp2[i] = min(v1[i], dp2[i - 1] + v1[i]);
            ans = max({ans, dp1[i], abs(dp2[i])});
        }
        return ans;
    }
};
