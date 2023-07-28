#include <bits/stdc++.h> 
string completeString(int n, const vector<string>& a) {
    set<string> s;
    string ans = "";

    for (int i = 0; i < n; i++)
        s.insert(a[i]);

    for (const auto& i : a) {
        bool flag = true;
        int m = i.size();

        for (int j = 1; j <= m; j++) {
            string t = i.substr(0, j);
            if (s.find(t) == s.end()) {
                flag = false;
                break;
            }
        }

        if (flag) {
            if (ans.size() == m) {
                ans = min(ans, i);
            } else if (ans.size() < m) {
                ans = i;
            }
        }
    }

    if (!ans.empty())
        return ans;

    return "None";
}
