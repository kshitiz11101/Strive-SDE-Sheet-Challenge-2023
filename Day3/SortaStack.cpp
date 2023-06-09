#include <bits/stdc++.h> 
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()){
		return;
	}
	vector<int> v;
	while(!stack.empty()){
		v.push_back(stack.top());
		stack.pop();
	}
sort(v.begin(),v.end());
for(int i=0;i<v.size();i++){
	stack.push(v[i]);
}

}
