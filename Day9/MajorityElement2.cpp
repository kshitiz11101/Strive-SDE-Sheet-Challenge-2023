#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementII(vector<int> &arr) {
    vector<int> result;
    sort(arr.begin(), arr.end());
    int count = 1;
    int distinct = 0;
    int size = arr.size();

    if (size == 1) {
        result.push_back(arr[0]);
    } else if (size < 3) {
        result.push_back(arr[0]);
        result.push_back(arr[1]);
    } else {
        for (int i = 0; i < size; i++) {
            if (arr[i] == arr[i + 1]) {
                count++;
                distinct = 0;
            } else {
                if (count > size / 3) {
                    result.push_back(arr[i]);
                }
                distinct = 1;
                count = 1;
            }
        }
        if (distinct == 0 && count > size / 3) {
            result.push_back(arr[size - 1]);
        }
    }

    return result;
}
