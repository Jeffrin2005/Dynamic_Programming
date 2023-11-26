#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define ll long long 
#define mod (int )(1e9 + 7)
#define nl  '\n'
#define modd 1000000007
//     FIBONACCI
void solve(){
    ll n;
    cin>>n;
    dp[0] = 0;
    dp[1] = 1;
    for(ll i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n] << nl; 
}
                                                LECTURE - 1
    DICE COMBINATION - COUNT NO OF WAYS
void solve(){
    ll n;
    cin>>n;
    vector<ll>dp(n+1);
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=6; j++){
            if(j<=i){
                dp[i]  = (dp[i] + dp[i-j]) % mod;
            }
        }
    }
    cout << dp[n] << nl;
}
    DICE COMBINATION - (LEETCODE CLIMBING STAIRS)
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int>dp(n+1,-1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++){
            dp[i] = (dp[i-1] + dp[i-2]);
        }
        return dp[n];
    }
};
     DICE COMBINATION - (LEETCODE MIN COST CLIIMBING STAIRS) - minimum way
  class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
          int n = cost.size();
        vector<int> dp(n + 1); 
        for (int i = 2; i <= n; i++) {
            int jumpOneStep = dp[i - 1] + cost[i - 1];  
            int jumpTwoStep = dp[i - 2] + cost[i - 2];  
            dp[i] = min(jumpOneStep, jumpTwoStep);
        }
        return dp[n];
    }
}; 
    DICE COMBINATION - (LEETCODE MIN COST CLIIMBING STAIRS) - minimum way ALTERNATIVE APPROACH
 
class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        std::vector<int> dp(n);
 
        dp[0] = cost[0];
        dp[1] = cost[1];
 
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + std::min(dp[i - 1], dp[i - 2]);
        }
 
        return std::min(dp[n - 1], dp[n - 2]);
    }
};
                                                LECTURE - 2
    MINIMIZING COINS = MINIMUM NO OF COINS
void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<int>dp(x+1,1e9);
    dp[0] = 0;
    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(a[j] <= i){
                dp[i]  = min(dp[i],dp[i-a[j]]+1);
            }
        }
    }
    cout << (dp[x] < 1e9 ? dp[x] : -1) <<nl;
}
    MAXIMUM CUTS = MAXIMUM NO OF RIBBON PIECES (CUT RIBBON)
void solve(){
  ll n,a,b,c;
  cin>>n>>a>>b>>c;
  vector<ll>dp(n+1,INT_MIN);
  dp[0] = 0;
  for(ll i=1; i<=n; i++){
    if(i >= a){
        dp[i] = max(dp[i],dp[i-a] + 1);
    }
    if(i >= b){
        dp[i] = max(dp[i] , dp[i-b] + 1);
    }
    if(i >= c){
        dp[i] = max(dp[i],dp[i-c] + 1);
    }
  }
  cout << dp[n] << nl;
}
    TETRAHEDRON - COUNT NO OF  WAYS
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(4, 0));
    dp[0][3] = 1;
    for(int i = 1; i <= n; ++i){
        for(int vertex = 0; vertex < 4; ++vertex) {
            for (int neighbor : {0, 1, 2, 3}){
                if(vertex != neighbor){
                    dp[i][vertex] = (dp[i][vertex] + dp[i - 1][neighbor]) % MOD;
                }
            }
        }
    }
    cout << dp[n][3] << nl;
}
         END OF LECT 2
        BOREDOM - MAXIMUM NO OF POINTS
void solve(){
   int  n;
    cin >> n;
    vector<ll> v(n);
    int m = 0;
    for(ll i = 0; i < n; i++) {
        cin >> v[i];
        m = max(m,v[i]);
    }
    ll cnt[100005] = {0};
    for(int i = 0; i < n; i++) 
        cnt[v[i]]++;
    
    ll dp[100005];
    dp[0] = 0;
    dp[1] = cnt[1];
    for(ll i = 2; i <= m; i++){
        dp[i] = max(dp[i-1],i*cnt[i] + dp[i-2]);
    }
    cout << dp[m] << nl;
 
}
 
        POTIONS - MAXIMUM NO OF POTIONS 
void solve(){
 ll n;
 cin>>n;
 vector<ll> a(n);
 for(ll i=0; i<n; i++) cin>>a[i];
 vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
for(int i=0;i<n;i++) dp[i][0]=0;
dp[0][1]=a[0];
for(int i=1;i<n;i++){
  for(int j=1;j<=n;j++){
    if(dp[i-1][j-1]>=0){
      dp[i][j]=max(dp[i-1][j-1]+a[i],dp[i][j]);
    }
    dp[i][j]=max(dp[i][j],dp[i-1][j]);
  }
}
ll res=0;
for(ll j=1;j<=n;j++){
  if(dp[n-1][j]>=0) res=max(res,j);
}
cout << res << nl;
}
 
                LECTURE 3 
        COIN COMBINATION - COUNT NO OF DISTINCT WAYS
void solve(){
    int n,x;
    cin>>n>>x;
    vector<int>dp(x+1,-1);
    vector<int>a(n);
    for(auto&x : a) cin>>x;
    dp[0] = 1;
    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(a[j] <= i){
                dp[i] = (dp[i] + dp[i-a[j]]) % mod;
            }
        }
    }
    cout << dp[x] << nl;
}
        COIN CHANGE - LEETCODE - MINIMUM NO OF COINS
void solve(){
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX-1);
        int n = coins.size(), i, j;
        dp[0] = 0; // no coins when amount = 0
        for(i=1; i<=amount; i++){
            for(j=0; j<n; j++){
                if(coins[j]<=i)
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
        
        if(dp[amount] == INT_MAX-1)
            return -1;
        else
            return dp[amount];
    }
 
}                     LECTURE - 4
//         COIN COMBINATION II - COUNT NO OF WAYS DISTINCT WAYS
void solve(){
    ll n,x;
    cin>>n>>x;
    vector<ll>a(n);
    for(auto&x : a) cin>>x;
    vector<ll>dp(x+1,0);
    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=1; j<=x; j++){
            if(j - a[i] >= 0){
            dp[j] = (dp[j] + dp[j-a[i]]) % mod;
        }
    }
    }
    cout << dp[x] << nl;
}
            COIN COMBINATION II - COUNT NO OF WAYS DISTINCT WAYS (ANOTHER METHOD)
void solve(){
    ll n,x;
    cin>>n>>x;
    vector<int>v(n);
    for(auto &it:v) cin>>it;
    vector<vector<int>>dp(n+1,vector<int>(x+1));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    for(int i=n-1;i>=0;i--){
        for(int sum=1;sum<=x;sum++){
            int skip=dp[i+1][sum];
            int pick=0;
            if(v[i]<=sum)
            {
                pick=dp[i][sum-v[i]];
            }
            dp[i][sum]=(skip+pick)%mod;
        }
    }
    cout<<dp[0][x]<<endl;
}
                    ADD ONE (LENGTH OF THE DIGIT CODEFORCES)
        void solve() {
    string str;
    cin >> str;
    ll m;
    cin >> m;
    ll ans = (ll)str.size();
    for(int i = 0; i < str.size(); i++){
        ans = (ans + dp[str[i] - '0'][m]) % MOD;
    }
    cout << ans << endl;
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp.resize(10, vector<ll>(2e5 + 1, 0ll));
    for(int j = 1; j <= 2e5; j++){
        for(int i = 0; i < 10; i++){
            if(i == 9){
                dp[i][j] = (1ll + dp[0][j - 1] + dp[1][j - 1]) % MOD;
            }else{
                dp[i][j] = dp[i + 1][j - 1];
            }
        }
    }
                                    LECTURE -  6
                REMOVING DIGITS (MINIMUM NO OF STEPS )
void solve(){
    ll n;
    cin>>n;
    vector<int>dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        string a = to_string(i);
        for(auto&x : a){
            ll digit = x - '0';
            if(digit != 0){
                dp[i] = min(dp[i],dp[i-digit] + 1);
            }
        }
    }
    cout << dp[n] << "\n";
}
                BASKET BALL EXERCISE - MAXIMUM HEIGHT 
void solve(){
    int n; 
    cin >> n; 
    ll h[n+1][2]; 
    vector<vector<ll>>dp(n+1,vector<ll>(2));
    for(ll i=1; i<=n; ++i){
        cin >> h[i][0]; 
    }
    for(int i=1; i<=n; ++i){
        cin >> h[i][1]; 
    }
    for(int i=1; i<=n; ++i){
        for(int j=0; j<2; ++j){
            dp[i][j] = h[i][j]; 
            if (i-1 >= 1) {
                dp[i][j] = max(dp[i][j], h[i][j] + dp[i-1][!j]); 
            }
            if (i-2 >= 1) {
                dp[i][j] = max(dp[i][j], h[i][j] + dp[i-2][!j]); 
            }
        }
    }
 
    cout << max(dp[n][0], dp[n][1]) << nl;
 
                 BLOCK SEQUENCE - MINIMUM NO OF REMOVAL
void solve(){
    ll n;
    cin >> n;
    vi v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];
    
    vi dp(n + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        if (v[i] + i < n) dp[i + v[i] + 1] = min(dp[i], dp[i + v[i] + 1]);
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    }
    cout << dp[n] << nl;
}
                         LECTURE - 9 BOOK SHOP taking maximum no of pages
    void solve(){
        ll n,x;
        cin>>n>>x;
        vector<int> val(n);
        vector<int>weight(n);
        for(int i=0; i<n; i++) cin>>weight[i];
        for(int i=0; i<n; i++) cin>>val[i];
            vector<vector<int>>dp(n+1,vector<int>(x+1));
        dp[0][0] = 0;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=x; j++){
                int w = weight[i-1];
                int value = val[i-1];
                int pick = (j >= w ? dp[i-1][j-w] + value : 0);
                int skip = dp[i-1][j];
                dp[i][j] = max(skip,pick);
            }
        }
        cout <<dp[n][x] << nl;
    }
                     LECTURE - 10 COUNTING TOWERS
 
void solve(){
     ll n;
        cin >> n;
        dp[n][0] = 1;
        dp[n][1] = 1;
        for(int i = n - 1; i >= 0; i--){
            dp[i][0] = (2LL * dp[i+1][0] + dp[i+1][1]) % mod;
            dp[i][1] = (4LL * dp[i+1][1] + dp[i+1][0]) % mod;
        }
        cout << (dp[1][0] + dp[1][1]) % mod << nl;
}
                    LECUTRE - 12
            EDIT DISTANCE MINIMUM NO OF OPER TO CONVER TO A STRING 
          
                     LECTURE - 11 RECTANGLE CUTTING
 we want to cut rectangle into square and square must be maximum and we want the minimum no of cuts to make it squares
void solve(){
  int a, b;
  cin >> a >> b;
  //for (int&v : arr) cin >> v;
  vector<vector<int>> dp(a+1,vector<int>(b+1,1e9));
  int ans = 0;
  dp[0][0] = 0;
  for(int i=0 ; i<=a ; i++){
    for(int j=0 ; j<=b ; j++){
    
      int mini = 1e9;
      for(int k=1 ; k<j ; k++){
        mini = min(mini, 1 + dp[i][k] + dp[i][j-k]);
      }
      dp[i][j] = mini;
      mini = 1e9;
      for(int k=1 ; k<i ; k++){
        mini = min(mini, 1 + dp[k][j] + dp[i-k][j]);
      }
      dp[i][j] = min(dp[i][j], mini);
    }
  }
  ans = dp[a][b];
  cout << ans << endl;

}
int main(){
   solve();
   return 0;
}
