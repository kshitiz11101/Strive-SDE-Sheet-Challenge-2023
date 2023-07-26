string kthPermutation(int n, int k) {
    int factorial = 1;
    vector<int> nums;
    for (int i = 1; i < n; i++) {
        factorial = factorial * i;
        nums.push_back(i);
    }
    nums.push_back(n);
    k = k - 1;
    string result = "";
    while (true) {
        result = result + to_string(nums[k / factorial]);
        nums.erase(nums.begin() + k / factorial);
        if (nums.size() == 0) {
            break;
        }
        k = k % factorial;
        factorial = factorial / nums.size();
    }
    return result;
}
