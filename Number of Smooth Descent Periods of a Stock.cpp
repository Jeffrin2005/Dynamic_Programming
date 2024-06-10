#include <bits/stdc++.h>
#define ll long long 
class Solution {
public:
    long long getDescentPeriods(vector<int>& a){
        ll n = a.size();
        vector<ll>dp(n,1);
        ll ans=1;
        dp[0]=1;
        for(int i=1;i<n;i++){
            if(a[i]+1==a[i-1]) dp[i]+=dp[i-1];
            
            ans+=dp[i];
        }
        return ans;
    }
};
