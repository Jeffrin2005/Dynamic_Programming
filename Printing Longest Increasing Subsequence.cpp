#include <vector>
#include <algorithm>
vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
    vector<int> dp(n, 1), parent(n, -1);
    int max_len = 1, last_end = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
                  if (dp[i] > max_len) {
            max_len = dp[i];
            last_end = i;
        }
            }
        }
    }
    vector<int> lis;
    while(last_end != -1){
        lis.push_back(arr[last_end]);
        last_end = parent[last_end];
    }
  // for printg lcs for(auto&x : list) cout << x << " "; cout << endl;
    reverse(lis.begin(), lis.end());  
    return lis;
}
