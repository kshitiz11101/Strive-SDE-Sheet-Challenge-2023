#include <bits/stdc++.h>

void generatePermutations(string &str, int index, vector<string> &result) {
    if (index == str.length()) {
        result.push_back(str);
        return;
    }

    for (int i = index; i < str.length(); i++) {
        swap(str[i], str[index]);
        generatePermutations(str, index + 1, result);
        swap(str[i], str[index]);
    }
}

vector<string> findPermutations(string &str) {
    vector<string> result;
    generatePermutations(str, 0, result);
    return result;
}
