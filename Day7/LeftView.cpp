#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int> *root,vector<int>&ans,int lvl){
    if(root==NULL){
        return;
    }
    if(lvl==ans.size()){
        ans.push_back(root->data);
    }
    solve(root->left,ans,lvl+1);
    solve(root->right,ans,lvl+1);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    int lvl=0;
    solve(root,ans,lvl);
    return ans;
}
