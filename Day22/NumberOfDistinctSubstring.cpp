#include <bits/stdc++.h> 

int distinctSubstring(const string& str) {
    set<string> result;

    for (int i = 0; i <= str.length(); i++) {
        for (int j = 1; j <= str.length() - i; j++) {
            result.insert(str.substr(i, j));
        }
    }

    return result.size();
}
