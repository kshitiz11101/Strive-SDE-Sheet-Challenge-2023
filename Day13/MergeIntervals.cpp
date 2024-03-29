#include <bits/stdc++.h>

/*



    intervals[i][0] = start point of i'th interval

    intervals[i][1] = finish point of i'th interval



*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &arr){
  // Write your code here.

  int n = arr.size();

  vector<vector<int>> ans;

  sort(arr.begin(), arr.end());

  vector<int> curr = arr[0];

  for (int i = 1; i < n; i++)

  {

    if (curr[1] >= arr[i][0])

    {

      curr[1] = max(curr[1], arr[i][1]);
    }

    else
    {

      ans.push_back(curr);

      curr = arr[i];
    }
  }

  ans.push_back(curr);

  return ans;
}
