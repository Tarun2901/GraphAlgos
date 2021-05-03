#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<bits/stdc++.h>
using namespace std;


bool checkusingBFS(int node,int V, vector<int> adj[], int color[])
{
  
   color[node] = 1;
   queue<int> q;
   q.push(node);
   while(!q.empty())
   {
   	int node = q.front();
   	q.pop();
   	for(auto it:adj[node])
   	{
   		if(color[it] == -1)
   		{   //Set color as opposite to that of node.
   			color[it] = 1-color[node];
   		}
   		else if(color[it] == color[node])
   		{
   			return false;
   		}
   	}
   }
   return true;
}

bool checkBipartite(int V,vector<int> adj[])
{
  int color[V+1];
  memset(color,-1,sizeof color);
  for(int i = 1;i<V+1;i++)
  {
  	if(color[i] == -1)
  	{
  		if(checkusingBFS(i,V,adj,color))
  		{
  			return true;
  		}
  	}
  }
  return false;
}

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
	vector<int> bfs;
	vector<int> vis(V+1,0);

	for(int i = 1;i<V+1;i++)
	{
		if(!vis[i])
		{
			 queue<int> q;
			//push the current node in queue
			q.push(i);
			//mark as visited
			vis[i] = 1;
			while(!q.empty())
			{
				int node = q.front();
				q.pop();
				bfs.push_back(node);
				//explore all the neighbours of the current node
				for(auto it:adj[node])
				{
					//If the neighbours is unvisited then push it into the queue and mark it as visited.
					if(!vis[it])
					{
						q.push(it);
						vis[it] = 1;
					}
				}
			}

		}
	}
	return bfs;
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

vector<int> bfs = bfsOfGraph(n,adj);
cout<<"BFS: ";
for(int i = 0;i<bfs.size();i++)
{
	cout<<bfs[i]<<" ";
}
cout<<endl;

cout<<"Is Bipartite? : "<<checkBipartite(n,adj)<<endl;
return 0;
}