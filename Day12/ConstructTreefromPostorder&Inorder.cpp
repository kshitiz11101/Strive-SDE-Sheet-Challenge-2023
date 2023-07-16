#include<map>
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
//  int findpos(vector<int> &inOrder,int element,int n){

//     for(int i=0;i<n;i++){

//         if(element==inOrder[i]){

//             return i;

//         }

//     }

//     return -1;

// }
void createMapping(vector<int> &inorder,map<int,int> &nodeToIndex,int n){
     for(int i=0;i<n;i++){
          nodeToIndex[inorder[i]]=i;
     }
} 
TreeNode<int>*solve(vector<int> &postOrder,vector<int> &inOrder,int &index,int instart,int inend,int n,map<int,int> &nodeToIndex){

    if(index<0 ||instart>inend){

        return NULL;

    }

    int element=postOrder[index--];

    TreeNode<int>*root=new TreeNode<int>(element);

    int pos=nodeToIndex[element];

    root->right=solve(postOrder,inOrder,index,pos+1,inend,n,nodeToIndex);
    root->left=solve(postOrder,inOrder,index,instart,pos-1,n,nodeToIndex);


    return root;

}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
      int n=inOrder.size();

    int postorderindex=n-1;
    map<int,int> nodeToIndex;
createMapping(inOrder,nodeToIndex,n);
    TreeNode<int>*ans=solve(postOrder,inOrder,postorderindex,0,n-1,n,nodeToIndex);

    return ans;

}
