#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
     vector<int>result;
        if(root==NULL){
            return result;
        }
        map<int,int> ans;
        queue<pair<TreeNode<int>*,int>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<TreeNode<int>*,int> temp=q.front();
            q.pop();
            TreeNode<int>*frontNode=temp.first;
            int hd=temp.second;
            // 1 to 1 mapping
            if(ans.find(hd)==ans.end()){
                ans[hd]=frontNode->val;
            }
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
                
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }
        for(auto i:ans){
            result.push_back(i.second);
        }
        return result; 

}
