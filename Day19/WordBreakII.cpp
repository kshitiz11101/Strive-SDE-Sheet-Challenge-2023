#include <bits/stdc++.h>

void solve(string str, unordered_set<string>& wordSet, vector<string>& result, string current) {
    if (str.size() == 0) {
        current.pop_back();
        result.push_back(current);
        return;
    }

    for (int i = 1; i <= str.size(); i++) {
        if (!wordSet.count(str.substr(0, i)))
            continue;
        solve(str.substr(i), wordSet, result, current + str.substr(0, i) + " ");
    }
}

vector<string> wordBreak(string& s, vector<string>& wordDict) {
    unordered_set<string> wordSet;
    wordSet.insert(wordDict.begin(), wordDict.end());

    vector<string> result;
    string current = "";

    solve(s, wordSet, result, current);

    return result;
}
