#include <bits/stdc++.h>
#include <bits/stdc++.h>
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
  // Write your code here.
  sort(arr.begin(), arr.end());
  int count = 1;
  int maxCount = 1;

  for (int i = 1; i < n; i++)
  {
    if (arr[i] - arr[i - 1] == 1)
      count++;

    else if (arr[i] - arr[i - 1] != 0)
      count = 1;

    maxCount = max(maxCount, count);
  }
  return maxCount;
}
