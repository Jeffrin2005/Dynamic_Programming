#include<bits/stdc++.h>
using namespace std;
#define ll long long 

bool check(vector<int>& v, ll k) {
    ll i = 0;
    ll n = v.size();
    ll j = n - 1;
    while (i <= j){
        while (i <= j and v[i] > k) i++;
        if (i > j) break;
        i++;
        j--;
        k--;
    }
    return k <= 0;
}
int32_t main(){
 
    int t;
    cin >> t;
    while (t--){
      ll n;
    cin >> n;
    vector<int>v(n);
    for (ll i = 0; i < n; i++) cin >> v[i];
    sort(v.rbegin(), v.rend());
    ll l = 0;
    ll r = 150; 
    while (l < r){
        ll mid = (l + r + 1) >> 1;
        if (check(v, mid)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    cout << l << "\n";
    }

    return 0;
}
