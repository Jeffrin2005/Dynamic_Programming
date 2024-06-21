#include <bits/stdc++.h>
#define ll long long 
class Solution {
private:
    int check(ll i, map<ll,ll>&dp){
        if(i  <= 1) return 0 ;
        if(dp.find(i) != dp.end()) return dp[i];
        
        if(i%2 == 0){
            dp[i] = 1 + check(i/2 , dp);
        }else{
            dp[i] = 1 + min(check(i+1,dp), check(i-1,dp));
        }
        return dp[i];
    }
public:
    int integerReplacement(int n) {
        map<ll,ll>dp;
        return check(n, dp);
        
    }
};
