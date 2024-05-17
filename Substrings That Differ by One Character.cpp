class Solution {
public:
    int countSubstrings(string s, string t) {
                int n = s.size();
        int m = t.size();
         s = "#" + s;
        t = "#" + t;
        vector<vector<int>> dp1(n+1,vector<int>(m+1));
        vector<vector<int>> dp2(n+1,vector<int>(m+1));
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i]==t[j]){
                    dp1[i][j] = 1 + dp1[i-1][j-1]; 
                    dp2[i][j] = dp2[i-1][j-1];
                }else{
                    dp2[i][j] = 1 + dp1[i-1][j-1]; 
                    }
                ans+=dp2[i][j];
     
            }
        }
        return ans;
    }
};
