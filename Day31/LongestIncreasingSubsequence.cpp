
#include<vector>   
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
     std::vector<int> sequence;
  sequence.push_back(arr[0]);
  int length = 1;
  for(int i = 1; i < n; i++)
  {
      if(arr[i] > sequence.back())
      {
          sequence.push_back(arr[i]);
          length++;
      }
      else
      {
          int index = lower_bound(sequence.begin(), sequence.end(), arr[i]) - sequence.begin();
          sequence[index] = arr[i];
      }
  }
    return length;
}
