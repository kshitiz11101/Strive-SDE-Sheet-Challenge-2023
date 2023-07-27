int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int result;

    if (n == 1) {
        return nums[0];
    }

    for (int i = 0; i < n - 1; i += 2) {
        // If adjacent elements are not equal, update result
        if (nums[i] != nums[i + 1]) {
            result = nums[i];
            break;
        }
    }

    // Update result
    if (nums[n - 2] != nums[n - 1]) {
        result = nums[n - 1];
    }

    return result;
}
