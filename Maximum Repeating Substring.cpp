
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        int m = word.size();
        vector<int> dp(n+1, 0);
        dp[0] = 0;// no need of this 
        int max_k = 0;
        for (int i = 0; i < n; i++){
            // Check if the substring ending at i matches `word`
            if (i + 1 >= m && sequence.substr(i - m + 1, m) == word) {
                // i - m < 0 check if its currnt_substring_length is < 0 then dp[i] = 1; else we count and goes to 
                // goes to dp[i-m](extending out substring length  + 1);
                if (i - m < 0) {
                    dp[i] = 1;
                } else {
                    dp[i] = dp[i - m] + 1;
                }
                max_k = max(max_k, dp[i]);
            }
        }
        return max_k;
    }
};

class Solution {
private:
    int check(const string &sequence, const string &word, const string &original_word, vector<int>& dp, int cnt) {
        if (sequence.find(word) == string::npos) {// not found in the sequence  
            return cnt;
        }
        int i = word.size() - original_word.size();
        if (dp[i] != -1) return dp[i];
        dp[i] = check(sequence, word + original_word, original_word, dp, cnt + 1);
        return dp[i];
    }

public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        vector<int>dp(n + 1, -1);
        int ans =  check(sequence, word, word, dp, 0);
        return ans; 
    }
};
// sequence = "ababc"
// word = "ab" (which is also the original_word in this context)
// dp is initialized with size n + 1 (where n is the length of sequence, so n + 1 = 6) and all values set to -1.
// Execution Flow:
// First Call to check:
// sequence = "ababc"
// word = "ab"
// original_word = "ab"
// dp = [-1, -1, -1, -1, -1, -1]
// cnt = 0
// Inside check:
// sequence.find(word) finds "ab" at index 0, so it's not npos.
// i = word.size() - original_word.size() = 2 - 2 = 0
// Since dp[0] is -1, we proceed with recursion.
// 2. Second Call to check:
// sequence = "ababc"
// word = "abab" (concatenated "ab" to the previous word)
// original_word = "ab"
// dp = [-1, -1, -1, -1, -1, -1]
// cnt = 1
// Inside check:
// sequence.find(word) finds "abab" at index 0, so it's not npos.
// i = word.size() - original_word.size() = 4 - 2 = 2
// Since dp[2] is -1, we proceed with recursion.
// Third Call to check:
// sequence = "ababc"
// word = "ababab" (concatenated "ab" to the previous word)
// original_word = "ab"
// dp = [-1, -1, -1, -1, -1, -1]
// cnt = 2
// Inside check:
// sequence.find(word) does not find "ababab" (it's longer than sequence), so it returns npos.
// This call returns cnt = 2.
// Back in the second call:
// dp[2] is set to 2 and returned.
// Back in the first call:
// dp[0] is set to 2 and returned.
// Final Output:
// The function maxRepeating returns 2, which is the maximum number of times "ab" can be repeated consecutively in "ababc" such that it still forms a substring of "ababc".
