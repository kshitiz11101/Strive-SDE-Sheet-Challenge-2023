#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{

  int profit = 0;

  int mini = prices[0];

  for (int i = 1; i < prices.size(); i++)
  {

    mini = min(prices[i], mini);

    profit = max(profit, (prices[i] - mini));
  }

  return profit;
}
