#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool solve(TreeNode<int>* root, int x, vector<int> &ans){

//BASE CONDITION

if(root==NULL) return false;

//IF NOT NULL, PUSH IN THE VECTOR

ans.push_back(root->data);

//IF CURRENT DATA MATCHES TO X MATCHES RETURN TRUE

if(root->data==x) return true;

//IF ANY OF LEFT OR RIGHT IS TRUE RETURN TRUE BECAUSE THE X HAS BEEN FOUND

if(solve(root->left,x,ans)||solve(root->right,x,ans)) return true;

//IF NOT FOUND AND BOTH LEFT AND RIGHT ARE FALSE, POP THE CURRENT VALUE OUT OF VECTOR

ans.pop_back();

//SIMULTANEOUSLY RETURN FALSE AS PATH NOT FOUND VIA THAT NODE

return false;

}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> ans;

if(root==NULL) return ans;

solve(root, x, ans);

return ans;
}
