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
class Solution {
public:
  ll dp[1001][12];
    int  x(int  xx, int  p, vec<vec<int>>&cost){
          int  yy = 2e9;
        if (xx < 0) return 0;
        if (dp[xx][p] != -1) return dp[xx][p];
      
        for(ll jj = 0; jj < 10; jj++) {
            if(jj == p){
                
            }else{ yy = min(yy, cost[xx][jj] + x(xx - 1, jj, cost));
                
}
        }
        return dp[xx][p] = yy;
    }

    int minimumOperations(vec<vec<int>>&grid) {
        memset(dp,-1, sizeof(dp));
        int n = sz(grid);
        int  m = grid[0].size();
        vec<vec<int>>v(m,vec<int>(11, 0));
        for(ll col = 0; col < m; col++){
            for(ll j = 0; j < 10; j++){
                for(ll row = 0; row < n; row++) {
                    if(grid[row][col] != j){
                        v[col][j] += 1;
        }
                }
            }
        }
        return x(m - 1, 10, v);
  }
};
