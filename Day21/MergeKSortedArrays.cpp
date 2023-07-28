#include <bits/stdc++.h>

vector<int> sortArray(vector<int> &A, vector<int> &B)
{
  int a = A.size();
  int b = B.size();
  vector<int> res(a + b);
  int i = 0, j = 0;
  while (i < a && j < b)
  {
    if (A[i] <= B[j])
    {
      res[i + j] = A[i++];
    }
    else
    {
      res[i + j] = B[j++];
    }
  }
  while (i < a)
  {
    res[i + j] = A[i++];
  }
  while (j < b)
  {
    res[i + j] = B[j++];
  }
  return res;
}

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
  // Write your code here.
  while (k != 1)
  {
    kArrays[0] = sortArray(kArrays[0], kArrays[k - 1]);
    k--;
  }
  return kArrays[0];
}
