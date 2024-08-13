// words: ["e", "a", "b"]
// groups: [0, 0, 1]
// Let's walk through how the code processes this input to produce the output ["e", "b"].
// Step-by-Step Execution:
// 1. Initialization:
// ans starts as an empty vector.
// i is initialized to 1, j is the size of groups (3), and store is set to the group of the first word (groups[0] which is 0).
// The first word "e" is added to ans because it's the starting point.
// 2. Recursive Processing:
// The helper function is called starting from the second word (index 1).
// At index 1 ("a"), the group is the same as store (0), so "a" is skipped.
// At index 2 ("b"), the group changes to 1. "b" is added to ans, and store is updated to 1.
// 3. Result:
// The ans vector now contains ["e", "b"].
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
