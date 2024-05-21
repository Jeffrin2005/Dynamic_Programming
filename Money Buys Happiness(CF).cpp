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
#define fr front
#define ss second
#define nl '\n' 
void solve(){
    ll m, x;
    cin >> m >> x;
    ll sum = 0;
   vi c(m+1);
   vi h(m+1);
    for(ll i = 1; i <= m; i++){
        cin>>c[i]; cin>>h[i];
        sum+=h[i];
    }
    vector<vector<ll>>dp(m+1, vector<ll>(sum+1, -1e11));
    dp[0][0] = 0;
    for(int i=1; i<=m; i++) dp[i][0] = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= sum; j++){
           dp[i][j] = dp[i-1][j] + x;
            if(j >= h[i] && (dp[i-1][j-h[i]]) - c[i] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-h[i]] - c[i] + x);
            }
        }
    }
    ll ans = 0;
    for(int j = 0; j <= sum; j++){
        if(dp[m][j] >= 0) ans = j;
    }
    cout << ans << nl;

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
