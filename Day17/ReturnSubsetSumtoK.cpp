void solve(vector<int> arr, int n, int k, int currentIndex, vector<vector<int>>& result, int currentSum, vector<int> currentSubset) {
    if (currentIndex >= n) {
        if (currentSum == k) {
            result.push_back(currentSubset);
        }
        return;
    }
    // Take
    currentSum += arr[currentIndex];
    currentSubset.push_back(arr[currentIndex]);
    solve(arr, n, k, currentIndex + 1, result, currentSum, currentSubset);
    // Not Take
    currentSum -= arr[currentIndex];
    currentSubset.pop_back();
    solve(arr, n, k, currentIndex + 1, result, currentSum, currentSubset);
    return;
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k) {
    vector<vector<int>> result;
    int currentSum = 0;
    vector<int> currentSubset;
    int currentIndex = 0;
    solve(arr, n, k, currentIndex, result, currentSum, currentSubset);
    return result;
}
