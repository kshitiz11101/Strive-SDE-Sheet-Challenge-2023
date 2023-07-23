#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
TreeNode<int>* Solve(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q){
if(root==NULL){
        return NULL;
    }
    if(root->data>=P->data && root->data<=Q->data){
        return root;
    }
    else if(P->data > root->data && Q->data > root->data ){
       return Solve(root->right,P,Q);
    }
    
     return Solve(root->left, P, Q);
    
    }
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
    if(P->data < Q->data){
        return Solve(root,P,Q);
    }
    return Solve(root,Q,P);
    
}
