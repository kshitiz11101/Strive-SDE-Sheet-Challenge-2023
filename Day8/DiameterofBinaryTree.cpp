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

// ************************************************************/
// int height(TreeNode<int> *root){
//     if(root==NULL){
//         return 0;
//     }
//   int left=height(root->left);
//    int right=height(root->right);
// int ans=max(left,right)+1;
// return ans;
// }
pair<int,int>DiameterFast(TreeNode<int> *root){
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }
    pair<int,int> left=DiameterFast(root->left);
    pair<int,int> right=DiameterFast(root->right);
    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second;
    pair<int,int> ans;
        ans.first=max(op1,(max(op2,op3)));
        ans.second=max(left.second,right.second)+1;
        return ans;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    return DiameterFast(root).first;
}
