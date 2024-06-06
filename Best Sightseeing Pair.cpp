class Solution{
public:
    int f(vector<int>& arr, int taken, int i, vector<vector<int>>& dp) {
        int n = arr.size();
        if(taken >= 2) return 0;
        if(i >= n ) return -1e7;
        if(dp[i][taken] != -1) return dp[i][taken];
    
         int pick = arr[i] + f(arr, taken + 1, i + 1, dp);
        if(taken == 1){
            pick = pick - i;
        }else{
            pick+=i;
        }
        int notPick = f(arr, taken, i + 1, dp);
         dp[i][taken] = max(pick, notPick);
         return  dp[i][taken];
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        return f(values, 0, 0, dp);
    }
};
