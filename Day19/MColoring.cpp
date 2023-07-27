#include<bits/stdc++.h>

bool safe(int node,vector<int> &color,unordered_map<int,list<int>> &adj,int col)

{

    for(auto it:adj[node])   

    {

        if(color[it]==col)

            return 0;

    }

    return 1;

}

bool dfs(int node,vector<int> &color,int N,int m,unordered_map<int,list<int>> &adj)

{

    if(node==N)

    {

        return 1;

    }

 

    for(int i=1;i<=m;i++)

    {

        if(safe(node,color,adj,i))

        {

            color[node]=i;

            if(dfs(node+1,color,N,m,adj)==1)

            {

                return 1;

            }

            color[node]=0;

        }

    }

    return 0;

}

string graphColoring(vector<vector<int>> &mat, int m) {

    // Write your code here

 

    unordered_map<int,list<int>> adj;

    for(int i=0;i<mat.size();i++)

    {

        for(int j=0;j<mat[i].size();j++)

        {

            if(mat[i][j]==1)

            {

                adj[i+1].push_back(j+1);

            }

        }

    }

 

  

    vector<int> color(mat.size()+1,0);

    

 

    // return "YES";

    return (dfs(1,color,mat.size()+1,m,adj)==1)?"YES":"NO";

}
