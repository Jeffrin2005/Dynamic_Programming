class Solution {
private:
    int fun(int i,int j,int score, vector<vector<int>>&dp, vector<int>&v){
        if(i >=j or j < 0 or i > v.size()-1)  return 0 ;
        if(dp[i][j] != -1) return dp[i][j];
        int pick1 = 0;
        int pick2 =0;
        int pick3 =0;
        if(v[i] + v[j] == score) pick1 = 1 + fun(i+1,j-1,score,dp,v);
        if(v[i] + v[i+1] == score) pick2 = 1 + fun(i + 2, j, score, dp, v);
        if(v[j] + v[j-1] == score) pick3 = 1 + fun(i, j-2 , score, dp ,v );
        dp[i][j] = max({pick2,pick3,pick1});
        return dp[i][j];

    }
public:
    int maxOperations(vector<int>& v) {
        int n = v.size();
        int i =0;
        int j = n - 1;
        int sum1 = v[i] + v[i+1];
        int sum2 = v[j] + v[j-1];
        int sum3 = v[i] + v[j];
        vector<vector<int>>dp1(n,vector<int>(n,-1));
        vector<vector<int>>dp2(n,vector<int>(n,-1));
        vector<vector<int>>dp3(n,vector<int>(n,-1));
        int check1 =  fun(i,j, sum1, dp1, v);
        int check2 = fun(i,j,sum2,dp2, v);
        int check3 = fun(i,j,sum3,dp3, v); 

        int ans = max({check1,check2,check3});
        return ans;         
    }
};
