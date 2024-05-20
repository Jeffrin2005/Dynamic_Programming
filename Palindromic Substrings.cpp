class Solution {
public:
    int countSubstrings(string s) {
int n = s.size();  
vector<vector<bool>> dp(n, vector<bool>(n, false));
int cnt = 0;
for (int diff = 0; diff < n; diff++) {
    for (int i = 0; i + diff < n; i++) {
        int j = i + diff;// s[n-i-1];
            if(diff==0){ //  a, b , c length of 1 
                    dp[i][j] = true;
                }
                else if(diff==1){// aa length of 2
                    if(s[i]==s[j]) dp[i][j] = true;
                    else dp[i][j] = false;
                }else{
                    if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1];
                    else dp[i][j] = false;
                }
                if(dp[i][j]) cnt++;
    }
}
return cnt;      
    }
};
