class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        s1 = '#' + s1;
        s2 = '#' + s2;
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        dp[0][0] = 0;
        for(int i =1; i<=n; i++) dp[i][0] = 0;
        for(int j=1; j<=m; j++) dp[0][j] = 0;

        for(int i =1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i] == s2[j]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(0 + dp[i-1][j], 0 + dp[i][j-1]);
            }
        }    
        int comm = dp[n][m];
        int temp1 = abs(n - comm);
        int temp2 = abs(m - comm);
        int org_ans = (temp1 + temp2);
        return org_ans;
    }
};
