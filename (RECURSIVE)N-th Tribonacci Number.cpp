// Step-by-Step Flow with n = 4
// Initialization:
// The tribonacci function is called with n = 4.
// A vector dp of size n+1 (i.e., 5) is created and initialized with -1 to indicate that no values have been computed yet.
// 2. Recursive Computation:
// The check function is called with i = 4 and the dp vector.
// Since dp[4] is -1, the function proceeds to compute check(3, dp), check(2, dp), and check(1, dp).
// 3. Breaking Down the Recursion:
// To compute check(3, dp), it needs check(2, dp), check(1, dp), and check(0, dp).
// check(2, dp) returns 1 immediately because it's a base case.
// check(1, dp) also returns 1 immediately (base case).
// check(0, dp) returns 0 (base case).
// Now, check(3, dp) can be computed as 1 + 1 + 0 = 2. This value is stored in dp[3].
// 4. Continuing the Recursion:
// Returning to the computation of check(4, dp), we now have:
// check(3, dp) is 2 (from memoization).
// check(2, dp) is 1 (base case).
// check(1, dp) is 1 (base case).
// check(4, dp) computes as 2 + 1 + 1 = 4. This value is stored in dp[4].
// 5. Result:
// dp[4], which is 4.

// The tribonacci function returns dp[4], which is 4
class Solution {
public:
    int check(int i, vector<int>& dp){
        if(i == 0) return 0;
        if(i == 1) return 1;
        if(i == 2) return 1;
        if(dp[i] != -1) return dp[i];
        dp[i] = check(i-1, dp) + check(i-2, dp) + check(i-3, dp);
        return dp[i];
    }
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return check(n, dp);
    }
};
