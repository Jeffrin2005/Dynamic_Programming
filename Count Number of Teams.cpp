class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
            vector<vector<int>>dp(n,vector<int>(3,0)); // dp for increasing
                vector<vector<int>>dp1(n,vector<int>(3,0)); // dp1 for decreasing 
                for(int i=0; i<n; i++) dp[i][0] = 1;
                for(int i=0; i<n; i++) dp1[i][0] = 1;
        for(int k=1; k<=2; k++){
        for(int i=0; i<n; i++){
            int count=0;
            for(int j = 0; j<i; j++){
            if(rating[j] < rating[i]){
             count+=dp[j][k-1];
                }
        }
            dp[i][k]=count;
        }
    }
          for(int k=1; k<=2; k++){
               for(int i=0; i<n; i++){
                int count=0;
                for(int j=0; j<i; j++){
                if(rating[j] > rating[i]){
                    count += dp1[j][k-1];
                }
            }
            dp1[i][k] = count;
        }
    }
    int ans=0;
    for(int i=0; i<n; i++){
        ans+=dp[i][2]+dp1[i][2];
    }
    return ans;
    
    
}
    
};
