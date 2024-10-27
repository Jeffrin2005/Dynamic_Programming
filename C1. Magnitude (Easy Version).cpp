#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std; 
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
typedef vector<int> vi;
#define cl clear
#define stt string 
#define ll  long long 
#define ed end

#define vec vector
#define sz(a) int((a).size())
#define pp pop_back
#define minii min_element
#define maxii max_element
#define rv reverse
#define em empty
#define fd find
#define fr front
#define bg begin
#define bk back 
#define ppf pop_front
#define ppb pop_back
#define up upper_bound
#define lb lower_bound
#define no_cnt log10
#define pu push
#define in insert
#define er erase
#define pb push_back
#define accu accumulate
#define ff first
#define ss second
#define nl '\n' 
void solve(){
    ll n; 
    cin >> n;
     vi a(n);
     for(auto&x : a) cin>>x;
    vec<vec<ll>>dp(n,vec<ll>(2));
    dp[0][0] = abs(a[0]);
    dp[0][1] = a[0];
    for(ll i = 1; i < n;i++){
        dp[i][1] = dp[i - 1][1] + a[i]; 
        if(a[i] >= 0){
            dp[i][0] = dp[i - 1][0] + a[i];
        }else{
            dp[i][0] = max(dp[i - 1][0] + a[i], abs(dp[i - 1][1] + a[i]));
        }
    }
    cout << dp[n - 1][0] << nl;
}
int  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 // freopen("input.txt", "r",stdin);
 // freopen("output.txt", "w",stdout);
    ll t;
    cin >> t;
    while(t--){
    solve();
    }
    return 0;
}

 //  DerekYeh
