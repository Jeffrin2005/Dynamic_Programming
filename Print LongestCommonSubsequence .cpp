
struct Node {
    int prev_i, prev_j;
};

string findLCS(int n, int m, string &s1, string &s2) {
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));


    struct Node backtrack[n + 1][m + 1];

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                backtrack[i][j] = {i-1, j-1};
            }
            else if(dp[i-1][j] >= dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                backtrack[i][j] = {i-1, j};
            }
            else {
                dp[i][j] = dp[i][j-1];
                backtrack[i][j] = {i, j-1};
            }
        }
    }

    string res = "";
    Node current = {n, m};

    while(current.prev_i > 0 && current.prev_j > 0) {
        if(s1[current.prev_i-1] == s2[current.prev_j-1]) {
            res = s1[current.prev_i-1] + res;
        }
        current = backtrack[current.prev_i][current.prev_j];
    }

    return res;
}

