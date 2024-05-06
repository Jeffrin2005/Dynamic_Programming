int longestBitonicSubsequence(vector<int>& arr, int n) {
    vector<int>inc(n+1, 1);
    vector<int>dec(n+1, 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]) {
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
    }
    for (int i = n - 2; i >= 0; i--){
        for (int j = n - 1; j > i; j--){
            if(arr[j] < arr[i]){
                dec[i] = max(dec[i], dec[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, inc[i] + dec[i] - 1);
    }

    return ans;
}
