#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;


bool checkCyclewithDFS(int node, vector<int> adj[],vector<int> &vis,vector<int> &dfsvis)
{
   vis[node] = 1;
   dfsvis[node] = 1;
   for(int it:adj[node])
   {
    if(vis[it] == 0)
    {
      if(checkCyclewithDFS(it,adj,vis,dfsvis) == true)
      {
        return true;
      }
    }
    else if(dfsvis[it]==1)
    {
      return true;
    }
   }

   dfsvis[node] = 0;
   return false;
}

bool isCycle(int V,vector<int> adj[])
{
  vector<int>vis(V,0);
  vector<int>dfsvis(V,0);
  for(int i = 0;i<V;i++)
  {
    if(vis[i] == 0)
    {
      if(checkCyclewithDFS(i,adj,vis,dfsvis))
      {
         return true;
      }
    }
  }
  return false;
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

cout<<"Is Cyclic? : "<<isCycle(n,adj)<<endl;
return 0;
}