
class Solution {
public:
    void check(vector<string>& ans, vector<string>& words, vector<int>& groups, int i, int j, int prev_color){
        if (i == j)   return;// i reach end of the group size 
        
        if(groups[i] != prev_color){
              prev_color = groups[i];
            ans.push_back(words[i]);
        }
        check(ans, words, groups, i + 1, j, prev_color);
    }

   vector<string> getLongestSubsequence(vector<string>& words,vector<int>& groups){
       vector<string>ans;
        int i = 1;
        int j = groups.size();
        int  prev_color = groups[0];
        ans.push_back(words[0]);
        check(ans, words, groups, i, j, prev_color);
        return ans;
    }
};
