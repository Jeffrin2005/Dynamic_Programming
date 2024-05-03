class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
          int n= s1.size();
        int m = s2.size();
          vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
         s1 = "#" + s1;
        s2 = "#" + s2;
        string res; 	
          dp[0][0] = 0;
        for(int i=1; i<=n; i++) dp[i][0] = 0;
        for(int i=1;i<=m; i++) dp[0][i] = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if(s1[i] == s2[j]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else  dp[i][j] = max(0 +  dp[i][j - 1], 0 + dp[i - 1][j]);
            }
        }
    int i=n,j=m;
    while(i>=1 && j>=1){
        if(s1[i]==s2[j]){
            res.push_back(s1[i]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                res.push_back(s1[i]);// if the longest of the s1 is greater thatn longes of s2 , 
                // we take short subseqen from longest s1 simmilart
                //  for longest s2  like it longest s2 > long..s1...
                i--;
            }else{
                res.push_back(s2[j]);
                j--;
            }
        }
    }
    while(i>=1){
        res.push_back(s1[i]);
        i--;
    }
    while(j>=1){
        res.push_back(s2[j]);
        j--; 
    }
        reverse(res.begin(),res.end()); 
        return res;
    }
};
