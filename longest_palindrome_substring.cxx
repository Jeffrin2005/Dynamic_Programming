class Solution
{
    public:

   static bool comp(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    }
  int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>vec;
        
        for(int i=0;i<n;i++){
            vec.push_back({end[i],start[i]});
        }
        sort(vec.begin(),vec.end());
        int ans=1;
        int limit=vec[0].first;
        for(int i=1;i<n;i++){
            if(vec[i].second>limit){
                ans++;
                limit=vec[i].first;
            }
        }
        return ans;
    }


};
