
class Solution {
public:
    int longestSubarray(vector<int>& nums){
        int n = nums.size();
        vector<int> left(n, 0), right(n, 0);
        // Fill the left array
        for (int i = 0; i < n; i++){
            if (nums[i] == 1){
                if(i == 0){
                    left[i] = 1;
                }else{
                    left[i] = left[i - 1] + 1;
                }
            }
        }
        // Fill the right array
        for (int i = n - 1; i >= 0; i--){
            if (nums[i] == 1) {
                if (i == n - 1) {
                    right[i] = 1;
                } else {
                    right[i] = right[i + 1] + 1;
                }
            }
        }
        // Calculate the maximum length of 1's subarray after removing one element
        int ans = 0;
        for (int i = 0; i < n; i++){
            int leftPart;
            int rightPart;
            // Calculate leftPart
            if (i == 0){
                leftPart = 0;
            } else {
                leftPart = left[i - 1];
            }

            // Calculate rightPart
            if (i == n - 1){
                rightPart = 0;
            }else{
                rightPart = right[i + 1];
            }
            ans = max(ans, leftPart + rightPart);
        }

        return ans;
    }
};
