#include<iostream>
#include<vector>
#include<queue>
using namespace std;


bool checkCycleDFS(int node,int prev,vector<int> adj[],vector<int> vis)
{
    vis[node] = 1;
    for(auto it:adj[node])
    {
    	if(vis[it]==0)
    	{   //Pass node as previous and check whether there exist a cycle for the adjacent nodes and return true if a cycle exists for
    		// the adjacent node
    		if(checkCycleDFS(it,node,adj,vis))
    		{
    			return true;
    		}
    	}
    	else if(it!=prev)
    		{
    			return true;
    		}
    	
    }
    return false;   
}

bool isCycle(int V,vector<int> adj[])
{
	vector<int> vis(V+1,0);
	for(int i = 1;i<V+1;i++)
	{
		if(!vis[i])
		{
			if(checkCycleDFS(i,-1,adj,vis))
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

bool ans = isCycle(n,adj);
cout<<"Is there a cycle in this graph? :"<<ans<<endl;
return 0;
}