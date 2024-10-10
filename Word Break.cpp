class Solution {// RECUR + MEMO 
private:
    bool check(string s, set<string>&set, vector<int>&dp, int start){
        if(start == s.size()) return true;
        if(dp[start] != -1) return dp[start];
        for(int i=start; i<s.size(); i++){
            if(set.count(s.substr(start,i+1-start)) && check(s,set,dp,i+1)){
                dp[start] = true;
                return true; 
            }
        }
        dp[start] = false;
        return false;
    
    }
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        set<string>set(wordDict.begin(),wordDict.end());
        return check(s, set, dp , 0);
        
    }
};// TABULATION
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string> set(wordDict.begin(), wordDict.end()); 
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && set.count(s.substr(j,i-j))){
                    dp[i] = true;
                    break; 
                }
            }
        }
        return dp[n];
    }
};
