#include<bits/stdc++.h>
using namespace std;


void topoDFS(int node,vector<int> adj[],vector<int> &vis, stack<int> &st)
{
	vis[node] = 1;
	for(auto it:adj[node])
	{
		if(vis[it] == 0)
	    {
	    	topoDFS(it,adj,vis,st);
	    }
	}
	st.push(node);
}

vector<int> toposort(int V,vector<int> adj[])
{
	vector<int>vis(V,0);
	vector<int>topo;
	stack<int> st;
    for(int i = 0;i<V;i++)
    {
    	if(vis[i]==0)
    	{
    		topoDFS(i,adj,vis,st);
    	}
    }
    while(!st.empty())
    {
    	topo.push_back(st.top());
    	st.pop();
    }
    return topo;
}

int main()
{
   int n,m;
   cin>>n>>m;
   vector<int> adj[n];

   for(int i = 0;i<m;i++)
   {
   	int u,v;
   	cin>>u>>v;
   	adj[u].push_back(v);
   }
   for(int i = 0;i<n;i++)
   {
   	cout<<"For edge "<<i<<" the adjacent vertices are: ";
   	for(int it:adj[i])
   	{
   		cout<<it<<" ";
   	}
   	cout<<endl;
   }
   vector<int> ans = toposort(n,adj);

   for(int i = 0;i<ans.size();i++)
   { cout<<ans[i]<<" ";
   }
	return 0;
}