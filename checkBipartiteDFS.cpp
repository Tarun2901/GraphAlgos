#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

bool checkusingDFS(int node,int V,vector<int> adj[],int color[])
{  //This if check is to ensure that we are only changing the color for unvisited node while first recursive call.
   if(color[node] == -1)
   {
      color[node] = 1;
   }
   for(int it:adj[node])
   {
      if(color[it] == -1)
      { //set color of the adjacent node as opposite to that of this node
        color[it] = 1 - color[node];
        if(!checkusingDFS(it,V,adj,color))
        {
          return false;
        }
      }
      else if(color[it] == color[node])
      {
        return false;
      }
   }
   return true;
}

bool checkBipartite(int V,vector<int> adj[])
{
    int color[V+1];
    memset(color, -1, sizeof color);
    for(int i = 1;i<V+1;i++)
    {
      if(color[i] == -1)
      {
        if(!checkusingDFS(i,V,adj,color))
        {
          return false;
        }
      }
    }
    return true;
}
void dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &storeDFS)
{
      storeDFS.push_back(node);
      vis[node] = 1;
      //Now apply recursively dfs on all unvisited adjacent nodes.
      for(auto it:adj[node])
      {
      	if(!vis[it])
      	{
      		dfs(it,adj,vis,storeDFS);
      	}
      }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
   vector<int> storeDFS;
   vector<int> vis(V+1,0);
   //Driver code as we might have the case of connected components being present in the graph
   for(int i = 1;i<V+1;i++)
   {
   	if(!vis[i])
   	{
   		dfs(i,adj,vis,storeDFS);
   	}
   }
   return storeDFS;
}

int main()
{
int n,m;
cin>>n>>m;
vector<int>adj[n+1];
for(int i = 0;i<m;i++)
{
int u,v;
cin>>u>>v;
adj[u].push_back(v);
adj[v].push_back(u);
}

for(int i = 1;i<n+1;i++)
{   cout<<"For "<<i<<" adjacent nodes are: ";
	for(int k:adj[i])
	{
		cout<<k<<" ";
	}
	cout<<endl;
}

cout<<"DFS: ";
vector<int> dfs = dfsOfGraph(n,adj);
for(int i = 0;i<dfs.size();i++)
{
	cout<<dfs[i]<<" ";
}

cout<<"Is Bipartite? : "<<checkBipartite(n,adj)<<endl;
return 0;
}