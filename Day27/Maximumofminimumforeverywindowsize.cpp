#include <bits/stdc++.h>

vector<int> maxMinWindow(vector<int>& arr, int n) {
  stack<int> stk;
  vector<int> leftSmall(n + 1, -1),
              rightSmall(n + 1, n);

  for (int idx = 0; idx < n; idx++) {
    while (!stk.empty() && arr[stk.top()] >= arr[idx])
      stk.pop();
    if (!stk.empty())
      leftSmall[idx] = stk.top();
    stk.push(idx);
  }

  while (!stk.empty())
    stk.pop();

  for (int idx = n - 1; idx >= 0; idx--) {
    while (!stk.empty() && arr[stk.top()] >= arr[idx])
      stk.pop();
    if (!stk.empty())
      rightSmall[idx] = stk.top();
    stk.push(idx);
  }

  vector<int> maximumValues(n + 1, INT_MIN), result(n);
  for (int idx = 0; idx < n; idx++) {
    int length = rightSmall[idx] - leftSmall[idx] - 1;
    maximumValues[length] = max(maximumValues[length], arr[idx]);
  }

  for (int idx = n - 1; idx >= 1; idx--)
    maximumValues[idx] = max(maximumValues[idx], maximumValues[idx + 1]);

  for (int idx = 1; idx <= n; idx++)
    result[idx - 1] = maximumValues[idx];

  return result;
}
