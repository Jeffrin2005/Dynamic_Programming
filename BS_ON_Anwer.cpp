class Solution {
public:

special array leetcode problem 
    int specialArray(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int low = 0 , high = *max_element(nums.begin(),nums.end());

       int mid = low + (high-low)/2;

       while(low<=high){
        
          int cnt = 0;
          for(auto it : nums){
            if(it>=mid) cnt++;
          }
          if(cnt==mid) return mid;

          if(cnt<mid) high = mid-1;
          else low = mid+1;

          mid = low + (high-low)/2;
       } 
       return -1;
    }
};
