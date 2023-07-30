#include <bits/stdc++.h>
int solve(vector<int> &values, vector<int> &weights, int n, int capacity)
{
  vector<int>prev(capacity+1,0);
    vector<int>curr(capacity+1,0);
    
    for(int w=weights[0];w<=capacity;w++)
    {
        if(weights[0]<=capacity)
        {
            prev[w]=values[0];
        }
        else
        {
            prev[w]=0;
        }
    }
    
    for(int index=1;index<n;index++)
    {
        for(int w=0;w<=capacity;w++)
        {
            int include=0;
            int exclude=0;
            if(weights[index]<=w)
           
               include=values[index] +prev[w-weights[index]];
                exclude=0+prev[w];
                curr[w]=max(include,exclude);

        }
       prev=curr;
    }
    return prev[capacity];    
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	return solve(values,weights,n,w);
}
