#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            for (int k = j + 1, m = n - 1; k < m;) {
                if (arr[i] + arr[j] + arr[k] + arr[m] == target) return "Yes";
                else if (arr[i] + arr[j] + arr[k] + arr[m] > target) m--;
                else k++;
            }
        }
    }
    return "No";
}
