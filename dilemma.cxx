#include <bits/stdc++.h>
using namespace std; 
#define ll long long unsigned
#define nl '\n'
#define pb push_back
#define ff first
#define ss second
typedef vector<int> vi;
#define mod (int )(1e9 + 7)
const int MAXN = 2e5 + 5;
#define MAX 100007
//avetqvtbybybv4wtqveyvqyv
const int N = 2e5 + 10;
const int MX = 1e7+5;
bool check(ll x, vi&a, vi&b, ll n){
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if (a[i] > x) {
            sum += b[i];
        }
    }
    return sum <= x;
}
void solve(){
    ll n;
    cin>>n;
    vi a(n);
    vi b(n);
   for(ll i=0; i<n; i++) cin>>a[i];
   for(ll i=0; i<n ; i++) cin>>b[i];
    ll l =0;
    ll r = 1e9;
    while(l < r){
        ll mid = (l + r) >> 1;
        if(check(mid, a, b, n)){
            r = mid;
        }
        else l = mid + 1;
    }
    cout << r << nl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
