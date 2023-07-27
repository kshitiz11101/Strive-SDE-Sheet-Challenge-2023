#include <bits/stdc++.h>
using namespace std;

int ninjaAndLadoos(vector<int> &arr1, vector<int> &arr2, int n, int m, int k) {
  if (n > m)
    return ninjaAndLadoos(arr2, arr1, m, n, k);

  int low = max(0, k - m), high = min(n, k); // cannot take all elements 
  while (low <= high) {
    int split1 = (low + high) >> 1;
    int split2 = k - split1;

    int left1 = split1 == 0 ? INT_MIN : arr1[split1 - 1];
    int left2 = split2 == 0 ? INT_MIN : arr2[split2 - 1];
    int right1 = split1 == n ? INT_MAX : arr1[split1];
    int right2 = split2 == m ? INT_MAX : arr2[split2];

    if (left1 <= right2 and left2 <= right1)
      return max(left1, left2);
    else if (left1 > right2)
      high = split1 - 1;
    else
      low = split1 + 1;
  }

  return 1;
}
