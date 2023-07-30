#include <bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n) {
    int minLength = INT_MAX;
    string minString = "";

    for (int i = 0; i < n; i++) {
        if (arr[i].size() < minLength) {
            minLength = arr[i].size();
            minString = arr[i];
        }
    }

    string prefix = "";
    int index = 0;

    while (index < minLength) {
        for (int i = 0; i < n; i++) {
            if (arr[i].at(index) != minString.at(index)) {
                return prefix;
            }
        }

        prefix += minString.at(index);
        index++;
    }

    return prefix;
}
