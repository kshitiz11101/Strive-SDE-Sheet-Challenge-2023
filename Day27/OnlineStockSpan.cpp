#include <bits/stdc++.h>

class StockPlanner {
private:
  stack<pair<int, int>> stk;

public:
  int next(int currentPrice) {
    int span = 1;
    while (!stk.empty() && currentPrice >= stk.top().first) {
      span += stk.top().second;
      stk.pop();
    }

    stk.push({currentPrice, span});
    return span;
  }
};

vector<int> findSpans(vector<int> &price) {
  vector<int> spans;
  StockPlanner planner;

  for (auto p : price) {
    int span = planner.next(p);
    spans.push_back(span);
  }

  return spans;
}
