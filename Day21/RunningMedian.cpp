#include <bits/stdc++.h>
using namespace std;

class RunningMedian {
private:
  priority_queue<int> maxi;
  priority_queue<int, vector<int>, greater<int>> mini;
  int maxs = 0, mins = 0;

public:
  void balanceHeaps() {
    if (mins > maxs) {
      maxi.push(mini.top());
      maxs++;

      mini.pop();
      mins--;
    }
  }

  void insert(int num) {
    maxi.push(num);
    maxs++;

    mini.push(maxi.top());
    mins++;

    maxi.pop();
    maxs--;

    balanceHeaps();
  }

  int getMedian() const {
    if (maxs > mins)
      return maxi.top();
    return (maxi.top() + mini.top()) / 2;
  }
};

void findMedian(const int *arr, int n) {
  RunningMedian rm;
  for (int i = 0; i < n; i++) {
    rm.insert(arr[i]);
    cout << rm.getMedian() << " ";
  }
}
