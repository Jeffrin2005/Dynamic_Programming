
ll solve(vector<ll>& arr) {
    ll num = arr.size();
    ll s = 0;
    vector<vector<ll>> dp(num + 1, vector<ll>(2, 0));
    dp[num] = {0, 1};
    for(ll i = num - 1; i >= 0; i--){
        ll t = dp[i + 1][0];
        ll c = dp[i + 1][1];
        dp[i][0] = t + arr[i];
        dp[i][1] = c;
        ll tempSum = t + s + arr[i];
        ll tempCount = c + 1;
        if(tempSum > dp[i][0]){
            dp[i][0] = tempSum;
            dp[i][1] = tempCount;
        }
        s+=arr[i];
    }
    return dp[0][0];
}
void solve(){
       ll n;
        cin >> n;
        vector<ll>arr(n);
        for(ll i = 0; i < n; ++i) cin>>arr[i];
        ll result = solve(arr);
        cout <<  result << nl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int lim = 1e7;
   prime_in_vector( lim );
ll t;
cin>>t;
while(t--){
    solve();
    } 

 
    return 0;
}
   
