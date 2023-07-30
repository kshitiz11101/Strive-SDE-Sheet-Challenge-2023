#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
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

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
     vector<int> ans;

    if (root == NULL)

    {

        return ans;

    }

 

    // Using a map to store nodes at each horizontal distance and level

    map<int, map<int, vector<int>>> nodes;

 

    // Queue to perform level order traversal

    queue<pair<TreeNode<int>*, pair<int, int>>> q;

 

    // Pushing root node with horizontal distance 0 and level 0

    q.push(make_pair(root, make_pair(0, 0)));

 

    while (!q.empty())

    {

        pair<TreeNode<int>*, pair<int, int>> temp = q.front();

        q.pop();

 

        TreeNode<int>* frontNode = temp.first;

        int hd = temp.second.first;

        int lvl = temp.second.second;

 

        // Storing the node's value at its corresponding horizontal distance and level

        nodes[hd][lvl].push_back(frontNode->data);

 

        // Enqueue left child with updated horizontal distance and level

        if (frontNode->left)

        {

            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));

        }

 

        // Enqueue right child with updated horizontal distance and level

        if (frontNode->right)

        {

            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));

        }

    }

 

    // Traverse the nodes map to retrieve the values in vertical order

    for (auto i : nodes)

    {

        for (auto j : i.second)

        {

            for (auto k : j.second)

            {

                ans.push_back(k);

            }

        }

    }

 

    // Return the vertical order traversal of the tree

    return ans;
}
