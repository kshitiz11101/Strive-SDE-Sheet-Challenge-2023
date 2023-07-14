double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	vector<int>ans;
        for(int i=0; i<a.size(); i++){
            ans.push_back(a[i]);
        }
        for(int i=0; i<b.size(); i++){
            ans.push_back(b[i]);
        }
        if(ans.size()==1)return ans[0];
        int n=ans.size();
        sort(ans.begin(), ans.end());
        
        if(n%2!=0){
            return ans[(n)/2];
        }
        else{
         
            return double(ans[(n/2)-1]+ans[(n/2)])/2;
        }
}
