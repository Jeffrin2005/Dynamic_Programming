class Solution {
private:
    int solve(vector<int>& arr, int k, int i, vector<int>& dp) {
        int n = arr.size();
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        int maxi = 0;
        int ans = 0 ; 
        for (int j = i; j < min(i + k, n); j++) {
            maxi = max(maxi, arr[j]);
            ans = max(ans, (j - i + 1) * maxi + solve(arr, k, j + 1, dp));
        }
        dp[i] = ans;
        return dp[i];
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, k, 0, dp);
    }
};


class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
          int n = arr.size();
    vector<int> dp(n + 1, 0); 
    dp[0] = 0; 

    for (int i = 1; i <= n; i++) {
        int maxi = INT_MIN;
        for (int j = 1; j <= k && i - j >= 0; j++) {
            maxi = max(maxi, arr[i - j]);
            dp[i] = max(dp[i], dp[i - j] + j * maxi);
        }
    }

    return dp[n]; // The answer for the whole array is stored in dp[n]
    }
};
// Outer Loop (i): Iterates from 1 to n, considering each position i in the array as the end of a subarray.
// Inner Loop (j): Iterates from 1 to k, considering all possible lengths of subarrays ending at position i. The condition i - j >= 0 ensures that the subarray does not start before the beginning of the array.
// maxi Calculation: Updates the maximum value found in the current subarray being considered.
