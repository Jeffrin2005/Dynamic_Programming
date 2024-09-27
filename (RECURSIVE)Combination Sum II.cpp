class Solution {
public:
    void backtrack(int start, int currentSum, int target,  vector<int>& candidates, vector<vector<int>>& result, vector<int>& combination){
        if (currentSum == target){
            result.emplace_back(combination);
            return;
        }
        
        // If the current sum exceeds the target, no need to proceed further
        if(currentSum > target){
            return;
        }
        for (int i = start; i < candidates.size(); i++){
            // Skip duplicates
            if(i > start && candidates[i] == candidates[i - 1]){
                continue;
            }
            // Include the current candidate in the combination
            combination.emplace_back(candidates[i]);
            // Since each number can only be used once, pass 'i + 1'
            backtrack(i + 1, currentSum + candidates[i], target, candidates, result, combination);
            // Exclude the last candidate to backtrack and explore other possibilities
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result; // To store all valid combinations
        vector<int> combination;  
        // Sort the candidates to handle duplicates
        sort(candidates.begin(), candidates.end());
        backtrack(0, 0, target, candidates, result, combination); 
        return result;
    }
};
