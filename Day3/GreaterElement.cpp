#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> ans(n);
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && s.top()<=arr[i]){
            s.pop();
        }

    ans[i]=s.empty()?-1:s.top();
       
            s.push(arr[i]);
        
    }
return ans;

}
