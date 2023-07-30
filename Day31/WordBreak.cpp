#include <bits/stdc++.h>

bool wordBreak(vector<string>& wordList, int n, string& target) {
    int i = 0;

    while (i < n) {
        if (target.find(wordList[i]) != target.npos) {
            target.erase(target.find(wordList[i]), wordList[i].size());
        } else {
            i++;
        }
    }

    if (target.size() == 0)
        return true;
    else
        return false;
}
