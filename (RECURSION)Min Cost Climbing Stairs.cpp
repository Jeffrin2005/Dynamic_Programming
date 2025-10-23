class Solution {
private:
    int check(int i, vector<int>cost,int n,  vector<int>&dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int one_climb = cost[i] + check(i + 1, cost, n , dp );
        int two_climb = cost[i] + check(i + 2, cost, n , dp);
        dp[i] = min(one_climb, two_climb);
        return dp[i];
        
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n + 1, -1);
        int start_from_0th_step = check(0, cost,n, dp ); 
        int start_from_1th_step = check(1, cost,n , dp );
        return  min(start_from_0th_step , start_from_1th_step);
    }
};
