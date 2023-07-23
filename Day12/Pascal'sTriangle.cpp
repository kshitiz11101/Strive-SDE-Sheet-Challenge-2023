#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> printPascal(int n) {
    vector<vector<long long int>> v;

    for (int i = 0; i < n; i++) {
        vector<long long int> ans;
        for (int j = 0; j < i + 1; j++) {
            ans.push_back(1);
        }
        v.push_back(ans);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < i; j++) {
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        }
    }

    return v;
}
