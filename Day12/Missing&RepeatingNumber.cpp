#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
  // Write your code here
  pair<int, int> ans;
  vector<int> a(n + 1, 0);
  a[0] = 1;
  for (int i = 0; i < n; i++)
  {
    if (a[arr[i]] == 1)
    {
      ans.second = arr[i];
    }
    a[arr[i]] = 1;
  }
  for (int i = 1; i < a.size(); i++)
  {
    if (a[i] == 0)
    {
      ans.first = i;
    }
  }
  return ans;
}
