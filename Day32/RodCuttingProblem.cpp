int cut(vector<int>& price,int ind,int n,vector<vector<int>>& dp){
	if(ind==0){
		return n*price[0];
	}
	if(dp[ind][n]!=-1) return dp[ind][n];
	int notpick=cut(price,ind-1,n,dp);
	int pick=INT_MIN;
	int rl=ind+1;
	if(rl<=n){
		pick=price[ind]+cut(price,ind,n-rl,dp);
	}
	return dp[ind][n]=max(pick,notpick);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n,vector<int>(n+1,-1));
	return cut(price,n-1,n,dp);
}
