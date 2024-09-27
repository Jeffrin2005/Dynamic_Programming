 public:
     void findSubsetSums(int index, int currentSum, std::vector<int>& arr, std::vector<int>& sums) {
        if (index == arr.size()) {
            sums.push_back(currentSum);
            return;
        }
        
        // Include the current element
        findSubsetSums(index + 1, currentSum + arr[index], arr, sums);
        
        // Exclude the current element
        findSubsetSums(index + 1, currentSum, arr, sums);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
  std::vector<int> sums;
        findSubsetSums(0, 0, arr, sums);
        return sums;
    }
