#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	vector<int> v;
for(int i=0;i<m;i++){
	v.push_back(arr1[i]);
}
for(int i=0;i<n;i++){
	v.push_back(arr2[i]);
}
sort(v.begin(),v.end());
return v;
}
