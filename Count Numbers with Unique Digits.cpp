class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(9);
        dp[0] = 1;
        vector<int> temp = {9, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        for(int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1];
            int prod = 1;
            for(int j = 0; j < i; j++)
                
                prod = prod * temp[j];
            dp[i] += prod; 
        }
        return dp[n]; 
    }
};
