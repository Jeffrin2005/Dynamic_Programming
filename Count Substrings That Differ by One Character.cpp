class Solution {
public:
    int countSubstrings(string s, string t) {
                int n = s.size();
        int m = t.size();
         s = "#" + s;
        t = "#" + t;
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        vector<vector<int>> dp1(n+1,vector<int>(m+1));
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i]==t[j]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    dp1[i][j] = dp1[i-1][j-1];
                }else{
                    dp1[i][j] = 1+dp[i-1][j-1];
                    }
                ans+=dp1[i][j];
     
            }
        }
        return ans;
    }
};
