int findpos(vector<int> &inorder,int element,int n){

    for(int i=0;i<n;i++){

        if(element==inorder[i]){

            return i;

        }

    }

    return -1;

}

TreeNode<int>*solve(vector<int> &inorder, vector<int> &preorder,int&index,int instart,int inend,int n){

    if(index>=n ||instart>inend){

        return NULL;

    }

    int element=preorder[index++];

    TreeNode<int>*root=new TreeNode<int>(element);

    int pos=findpos(inorder,element,n); 

    root->left=solve(inorder,preorder,index,instart,pos-1,n);

    root->right=solve(inorder,preorder,index,pos+1,inend,n);

    return root;

}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)

{

    //    Write your code here

    int n=inorder.size();

    int preorderindex=0;

    TreeNode<int>*ans=solve(inorder,preorder,preorderindex,0,n-1,n);

    return ans;

}
