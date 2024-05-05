class Solution {
public:
    bool checkPossible(string &s1, string &s2) {
        if (s1.size() != s2.size() + 1) return false;
        int first = 0;
        int second = 0;
        while (first < s1.size()) {
            if (second < s2.size() && s1[first] == s2[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }
        return second == s2.size();
    }
    static bool comp(const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n+1, 1);
        int maxi = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (checkPossible(words[i], words[j]) && 1 + dp[j] > dp[i]){
                    dp[i] = dp[j] + 1;
                    if (dp[i] > maxi) {
                        maxi = dp[i];
                    }
                }
            }
        }
        return maxi;
    }
};
