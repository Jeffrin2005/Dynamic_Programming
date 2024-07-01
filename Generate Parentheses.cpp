
class Solution {
private:
    void check(vector<string>& ans, int n, int open, int close, string curr) {
        if (curr.size() == n * 2) {
            ans.push_back(curr);
            return;
        }
        if (open < n) check(ans, n, open + 1, close, curr + "(");
        if (close < open) check(ans, n, open, close + 1, curr + ")");
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        check(ans, n, 0, 0, ""); 
        return ans; 
    }
};
