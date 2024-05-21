
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
    vector<vector<ll>>dp(m+1, vector<ll>(sum+1, -1e12));
    dp[0][0] = 0;
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
